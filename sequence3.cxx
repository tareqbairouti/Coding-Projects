// TAREQ BAIROUTI

// Invariant for this class
// 1) sequence is implemented using linked lists.
// 2) head_ptr variable points to the first node or NULL if sequence is empty.
// 3) tail_ptr variable points to the last node or NULL if sequence is empty.
// 4) cursor variable points to the current node or NULL if there isn't a current node.
// 5) precursor variable points to the node before the current node, or NULL if there isn't a current
// node or cursor is the first node.
// 6) many_nodes variable is used to keep track of number of nodes in the sequence.
// 7) If sequence is empty, then head_ptr, tail_ptr, cursor, and precursor must all be NULL, 
// and many_nodes must be 0.
// 8) The sequence is allocated using dynamic memory and is deallocated when sequence is destroyed.

#include "node1.h"
#include "sequence3.h"
#include <cassert>
#include <cstdlib>
namespace main_savitch_5
{
    sequence::sequence(){           // linked list: O(1) // dynamic array: O(1)
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
    }
    
    sequence::sequence(const sequence& source){             // linked list: O(n) // dynamic array: O(n)
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        if (source.cursor == NULL){
            cursor = NULL;
            precursor = NULL;}
        else{
            node* temp = source.head_ptr;
            node* temp2 = head_ptr;
            while (temp != source.cursor){ 
                temp = temp -> link();
                temp2 = temp2 -> link();}
            cursor = temp2;
            precursor = cursor -> link();}
    }
    
    sequence::~sequence(){                      // linked list: O(n) // dynamic array: O(1)
        list_clear(head_ptr);
        many_nodes = 0;
    }
    
    void sequence::start(){                     // linked list: O(1) // dynamic array: O(1)
        if(many_nodes != 0){
            cursor = head_ptr;
            precursor = NULL;
        }    
    }
    
    void sequence::advance(){                   // linked list: O(1) // dynamic array: O(1)
        assert(is_item());
        precursor = cursor;
        cursor = cursor -> link();
    }
    void sequence::insert(const value_type& entry){         // linked list: O(1) // dynamic array: O(n)
        if (is_item()){
            if (precursor == NULL || cursor == NULL){
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }
            else{
                list_insert(precursor, entry);
                cursor = precursor -> link();
            }
        }
        else{
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;
        }
        ++many_nodes;
    }
    void sequence::attach(const value_type& entry){        // linked list: O(1) // dynamic array: O(n)
        if (is_item()){
            precursor = cursor;
            list_insert(cursor, entry);
            cursor = cursor -> link();
        }
        else{
            if (head_ptr == NULL){
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }
            else{
                precursor = list_locate(head_ptr, list_length(head_ptr));
                list_insert(precursor, entry);
                cursor = precursor -> link();
            }
        }
        ++many_nodes;
    }
    void sequence::remove_current(){            // linked list: O(1) // dynamic array: O(n)
        assert(is_item());
        if (cursor == head_ptr){
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = NULL;}
        else
        {
            precursor->set_link(cursor->link());
            delete cursor;
            cursor = precursor->link();}
        --many_nodes;
    }
    void sequence::operator=(const sequence& source){       // linked list: O(n) // dynamic array: O(n)
        if (this == &source){
            return;}
        list_clear(head_ptr);
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        cursor = head_ptr;
        precursor = NULL;
        node* temp = source.head_ptr;
        while(temp != NULL & temp != source.cursor){
            temp = temp -> link();
            precursor = cursor;
            cursor = cursor -> link();}
    }
    sequence::size_type sequence::size() const{             // linked list: O(1) // dynamic array: O(1)
        return many_nodes;
    }
    bool sequence::is_item() const{                         // linked list: O(1) // dynamic array: O(1)
        return (cursor != NULL);
    }
    sequence::value_type sequence::current() const{         // linked list: O(1) // dynamic array: O(1)
        if(is_item()){
            return cursor->data();
        }
    }
}