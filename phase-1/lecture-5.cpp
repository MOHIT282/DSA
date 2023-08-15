#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int b = 4;
    cout << (a & b) << endl; // and
    cout << (a | b) << endl; // or
    cout << (a ^ b) << endl; // xor
    cout << (~ 2) << endl; // not
    cout<<endl;

    // left shift

    cout<< (5 << 1)<<endl; // left shift multiply by 2
    cout<< (5 << 2)<<endl;; // left shift multiply by 2x2
    cout<< (5 << 3)<<endl;; // left shift multiply by 2x2X2
    cout<<endl;
    // right shift

    cout<< (40 >> 1)<<endl; // left shift devide by 2
    cout<< (40 >> 2)<<endl;; // left shift devide by 2x2
    cout<< (40 >> 3)<<endl;; // left shift devide by 2x2X2

    // for large number it can make them negative as well therefore it is true for small integers only
    // in case of +ve number padding is always using 0 but in case of negative numbers, it is compiler negative
}