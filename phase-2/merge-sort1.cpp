#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n){

    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void merge(int arr[], int beg, int end){

    int mid = beg + (end - beg)/2;

    int leftArraySize = mid - beg + 1;
    int rightArraySize = end - mid;

    int *leftArray = new int[leftArraySize];
    int *rightArray = new int[rightArraySize];

    int mainArrayIndex = beg;

    // copying elements in the left array
    for(int i = 0; i < leftArraySize; i++){
        leftArray[i] = arr[mainArrayIndex++];
    }
    // cout<<"left array is : ";
    // printArray(leftArray, leftArraySize);

    // copying the elements in the right array
    for(int i = 0; i < rightArraySize; i++){
        rightArray[i] = arr[mainArrayIndex++];
    }

    // cout<<"right array is : ";
    // printArray(rightArray,rightArraySize);
 
    mainArrayIndex = beg;

    int i = 0, j = 0;
    
    while(i < leftArraySize && j < rightArraySize){

        if(leftArray[i] < rightArray[j]){
            arr[mainArrayIndex++] = leftArray[i++];
        }
        else{
            arr[mainArrayIndex++] = rightArray[j++];
        }
    }

    while(i < leftArraySize){
        arr[mainArrayIndex++] = leftArray[i++];
    }

    while(j < rightArraySize){
        arr[mainArrayIndex++] = rightArray[j++];
    }

    delete []leftArray;
    delete []rightArray;

}

void mergeSort(int arr[],int s, int e){

    if( s >= e)
        return;

    int mid = s + (e - s)/2;

    mergeSort(arr, s, mid);

    mergeSort(arr,mid+1, e);


    merge(arr,s,e);
}

int main(){
 
    int arr[12] = {12,45,63,89,23,46,72,13,27,30,55,78};

    mergeSort(arr,0,12);

    for(int i = 0; i < 12; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


}