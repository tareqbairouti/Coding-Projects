// TAREQ BAIROUTI

#include <iostream>
using namespace std;
#include "stats.h"
#include <cassert>

namespace main_savitch_2C
{
    statistician::statistician(){
        count = 0;
        total = 0;
    }
    
    
    void statistician::next(double r){
        count ++;
        total = total + r;
        assert(count > 0);
        if (count == 1){
            tinyest = r;
            largest = r;
        }
        if (count >= 2){
            if (r < tinyest){
                tinyest = r;
            }
            if (r > largest){
                largest = r;
            }    
        }
    }
    
    void statistician::reset(){
        count = 0;
        total = 0;
    }
    
    int statistician::length() const{
        return count;
    }
    
    double statistician::sum() const{
        return total;
    }
    
    double statistician::mean() const{
        return (total/count);
    }
    
    double statistician::minimum() const{
        return tinyest;
    }
    
    double statistician::maximum() const{
        return largest;
    
    }
    statistician operator+(const statistician& s1, const statistician& s2){
        if (s1.length( ) == 0)
        return s2;
        if (s2.length( ) == 0)
        return s1;
        statistician s3;
        s3.count = s1.count + s2.count;
        s3.total = s1.total + s2.total;
        if (s1.tinyest <= s2.tinyest){
            s3.tinyest = s1.tinyest;}
        else{
            s3.tinyest = s2.tinyest;}
        if (s1.largest >= s2.largest){
            s3.largest = s1.largest;}
        else{
            s3.largest = s2.largest;}
        return s3;
    }
    
    statistician operator*(double scale, const statistician& s){
        statistician s3;
        s3.total = scale * s.total;
        s3.count = s.count;
        s3.tinyest = s.tinyest * scale;
        s3.largest = s.largest * scale;
        
        if (scale > 0){
            s3.tinyest = s.tinyest * scale;
            s3.largest = s.largest * scale;
        }
        if (scale < 0){
            s3.tinyest = s.largest * scale;
            s3.largest = s.tinyest * scale;
        }
        
        return s3;
    }
    
    bool operator==(const statistician& s1, const statistician& s2){
        return (s1.length() == s2.length()) && (s1.sum() == s2.sum());
        assert(s1.length() > 0);
        assert(s2.length() > 0);
        (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum());
        
    }
}