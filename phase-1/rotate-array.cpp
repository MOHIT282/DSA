#include <bits/stdc++.h>
using namespace std;

void printArray (int arr[], int n){

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void rotateArr(int arr[], int d, int n){

    // function to rotate counter clockwise an array
        
        if (n == 1)
            return;
        
        cout<<"printing the original array : ";printArray(arr,7);
        cout<<"reverse (arr, arr+d) : "; reverse(arr, arr+d);
        printArray(arr,7);
        cout<<"reverse (arr+d, arr+n) : "; reverse(arr+d,arr+n);
        printArray(arr,7);
        cout<<"reverse (arr, arr+n) : ";reverse(arr,arr+n);
        printArray(arr,7);
        
    }


int main(){
    int arr[7] = {1,2,3,4,5,6,7};

    rotateArr(arr,2,7);

    printArray(arr,7);

}