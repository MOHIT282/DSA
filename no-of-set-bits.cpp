// count the no. of bits of an integer number

#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n){

    int count = 0;

    while( n > 0){

        count += n & 1;
        n = n>>1;
    }
    return count;
}


int main(){

    cout<<countSetBits(6)<<endl;
    cout<<countSetBits(13)<<endl;
}