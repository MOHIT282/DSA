// Check if a number is < Bleak >
// A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.
// Examples : 

// Input : n = 3
// Output : false
// 3 is not Bleak as it can be represented
// as 2 + countSetBits(2).

// Input : n = 4
// Output : true
// 4 is t Bleak as it cannot be represented 
// as sum of a number x and countSetBits(x)
// for any number x.

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




bool checkBleak(int num){

    int i = 0;

    while(i < num){

        if((i + countSetBits(i)) == num)
            return false;

        i++;
    }
    return true;
}


int main(){

    cout<<checkBleak(3)<<endl;
    cout<<checkBleak(4)<<endl;

}