// TAREQ BAIROUTI
// This file includes 1. functions 2. Implementations 3. Testing functions in "int main()"

#include <iostream>
using namespace std;
#include <cassert>

void binary_print(ostream& outs, unsigned int n){
    if (n == 0) {
        outs << 0;
        return;}
    binary_print(outs, n/2);
    outs << n%2;
    }

void triangle(ostream& outs, unsigned int m, unsigned int n){
    if (m > n) {return;}
    for (unsigned int i = 0; i < m; i++){
        outs << "*";}
    outs << endl;
    triangle(outs, m+1, n);
    for (unsigned int i = 0; i < m; i++){
        outs << "*";}
    outs << endl;
    }

double pow(double x, int n){
    if (x == 0){
        assert(n > 0);
        return 0;}
    if (n == 0) {
        return 1;}
    if (n < 0){
        return 1 / pow(x, -n);}
    double result = pow(x, n/2);
    if (n%2 == 0){
        return result * result;}
    else{
        return x * result * result;}
    }

void indented_sentences(size_t m, size_t n){
    if (m > n){return;}
    for (size_t i = 0; i < m; i++) {
        cout << " ";}
    cout << "This was written by calling number " << m << "." << endl;
    indented_sentences(m+1, n);
    for (size_t i = 0; i < m; i++) {
        cout << " ";}
    cout << "This was ALSO written by calling number " << m << "." << endl;
}

int main()
{
    cout << "Testing first function, I will test unsigned integer 0" << endl;
    cout << "result should be: 0" << endl;
    cout << "binary_print(cout, 0) returns:  ";
    binary_print(cout, 0);
    cout <<endl<< "Testing first function again with unsigned integer 27" << endl;
    cout << "result should be: 011011 >> 0*2^5 + 1*2^4 + 1*2^3 + 0*2^2 + 1*2^1 + 1*2^0" << endl;
    cout << "binary_print(cout, 27) returns:  ";
    binary_print(cout, 27);
    cout <<endl<<endl<<"Testing second function, I will test unsigned integers 3 & 5" << endl;
    cout << "result should be same as one in assignment prototype" << endl;
    cout << "triangle(3, 5) returns: " << endl;
    triangle(cout, 3, 5);
    cout << "Testing again with unsigned integers 1 & 6" << endl;
    cout << "triangle(1, 6) returns: " << endl;   
    triangle(cout, 1, 6);
    cout<<endl<<"Third function. Exponent is being halved in each recursive call, "<<endl;
    cout<<"Number of recursive calls is proportional to the logarithm of n. (O(log(n)))";
    cout <<endl<<endl<<"Testing fourth function, I will test 1 and 4" << endl;
    cout << "result should be same as one in assignment prototype" << endl;
    cout << "indented_sentences(1, 4) returns: " << endl;
    indented_sentences(1, 4);
    cout << endl << "Testing again with unsigned integers 2 and 6" << endl;
    cout << "indented_sentences(0, 5) returns: " << endl;
    indented_sentences(0, 5);
    return 0;
}