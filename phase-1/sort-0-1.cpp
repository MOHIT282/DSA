// we will sort this using 2 pointer approach
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){

        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void sortZeroOne(int arr[] , int size){

    int begin = 0, end = size - 1;

    while (begin < end)
    {
        while(arr[begin] == 0 ){
            begin++;
        }
        while(arr[end] == 1){
            end--;
        }
        if(begin < end){
            swap(arr[begin], arr[end]);
            begin++;
            end--; 
        }
    }
    printArray(arr,size);
}



int main(){

    int arr1[] = {0,1,0,0,1,1,0,1,1,0,0};

    sortZeroOne(arr1,11);

}