#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int> &arr, int rotationNumber){

    int size = arr.size();
    int k = rotationNumber;

    vector<int> temp(size);

    for(int i = 0; i< size; i++){

        temp[((i + k)% size)] = arr[i];
    }
    arr = temp;
}

int main(){

    vector<int> arr = {12,52,19,45,28,36};

    rotateArray(arr,3); // 45 28 36 12 52 19

    for(int i = 0; i< arr.size(); i++){

        cout<<arr[i]<<" ";
    }
    
}