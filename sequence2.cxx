// TAREQ BAIROUTI
// The invariant for this class
// 1. Items in the sequence are stored in a dynamic array (*data).
// 2. Number of items in the sequence is stored in (used).
// 3. Capacity of the dynamic array is stored in (capacity).
// 4. If there is a current item, then it lies in data[current_index];
// if there is no current item, then current_index equals used.

#include <iostream>
using namespace std;
#include "sequence2.h"
#include <cassert>
namespace main_savitch_4
{
    sequence::sequence(size_type initial_capacity){
        used = 0;
        current_index = 0;
        capacity = initial_capacity;
        data = new value_type[initial_capacity];
    }

    sequence::sequence(const sequence& source){
//    write the preconditions and postconditions yourself! for sequence(const sequence& source);
//      No preconditions
//      postcondition: A new sequence is made that has the same capacity and used as the
//      source, and contains the same data.
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        copy(source.data, source.data + used, data);
    }
    sequence::~sequence(){
        delete [] data; 
    } 

    void sequence::start( ){
        current_index = 0;
    }
    
    void sequence::advance( ){
        assert(is_item());
        current_index++;
    }
    
    void sequence::insert(const value_type& entry){
        if (used >= capacity){
            resize (1 + used);}
        if (!is_item()){
            current_index = 0;}
        for (size_type i = used; i > current_index; i--){
            data[i] = data[i-1];}
        data[current_index] = entry;
        used++;
        
    }
    
    void sequence::attach(const value_type& entry){
        if (used >= capacity){
            resize (1 + used);}
        if (!is_item()){
            current_index = used;
            data[current_index] = entry;}
        else 
        {
            for(size_type i = used; i > (current_index + 1); i--)
                data[i] = data[i-1];
            data[current_index + 1] = entry;
            current_index++;
        }
        used++;
    }
    
    void sequence::remove_current( ){
        assert (is_item());
        for (size_type i = current_index; i<used-1; i++){
            data[i] = data[i+1];}
        used--;
        
    }
    
    void sequence::resize(size_type new_capacity){
        if (new_capacity > used){
            capacity = new_capacity;
            value_type *new_data = new value_type[capacity];
            for (size_type i = 0; i < used; i++){
                new_data[i] = data[i];}
            delete[] data;
            data = new_data;
        }    
    }
    void sequence::operator=(const sequence& source){
        if(this != &source){
            //capacity = source.capacity;
            delete [] data;
            data = new value_type[source.capacity];
            used = source.used;
            current_index = source.current_index;
            copy(source.data, source.data + used, data);
            //for(int i=0;i<used;i++){
            //    data[i] = source.data[i];}
        }
    }
    
    sequence::size_type sequence::size() const{
        return used;
    }
    
    bool sequence::is_item() const{
        return current_index < used && current_index >= 0;
    }
        
    sequence::value_type sequence::current() const{
        assert(is_item());
        return data[current_index];
    }
}