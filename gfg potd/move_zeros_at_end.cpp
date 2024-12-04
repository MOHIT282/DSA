// you are given an array of integers, you have to move 0s to the end of this array inplace without changing the order of other elements

#include<bits/stdc++.h>
using namespace std;

void moveZerosToEnd(vector<int>& arr){

    // two pointer approach
    int i = 0, j = 0; // i is the pointer for the non-zero elements, j is the pointer for the zero elements
    while(j < arr.size()){ // traverse the array
        if(arr[j] != 0){ // if the element is not zero, then swap it with the element at the i pointer
            swap(arr[i], arr[j]);
            i++; // increment the i pointer
        }
        j++; // increment the j pointer
    }
}


int main(){
    vector<int> arr = {1,0,0,2,3,0,4,0,5,0}; // given array
    moveZerosToEnd(arr);
    for(int &num: arr) cout<<num<<" "; // print the array
    
}