#include <bits/stdc++.h>
using namespace std;


void printArray(int *arr, int n){

    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void merge(int *arr, int beg, int end){

    int mid = beg + (end - beg)/2;
    //we have to merge to arrays in sorted order
    //  first array is from beg to mid and 2nd array is from mid + 1 to end

    int leftArraySize = mid - beg + 1;
    int rightArraySize = end - mid;

    int *leftArray = new int[leftArraySize];
    int *rightArray = new int[rightArraySize];

    //copy the elements in left array
    int mainArrayIndex = beg;
    for(int i = 0; i < leftArraySize; i++){
        leftArray[i] = arr[mainArrayIndex++];
    }

    //copy the elements in right array
    for(int i = 0; i < rightArraySize; i++ ){
        rightArray[i] = arr[mainArrayIndex++];
    }

    // Now merge both the arrays in sorted order in the original array
    //create new indexes for left and right array to keep track of elements being pushed in main array

    int index1 = 0, index2 = 0;
    mainArrayIndex = beg;
    while(index1 < leftArraySize && index2 < rightArraySize ){

        if(leftArray[index1] < rightArray[index2]){
            arr[mainArrayIndex++] = leftArray[index1++];
        }
        else{
            arr[mainArrayIndex++] = rightArray[index2++];
            
        }
    }
    while(index1 < leftArraySize){
            arr[mainArrayIndex++] = leftArray[index1++];
    }
    while(index2 < rightArraySize){
            arr[mainArrayIndex++] = rightArray[index2++];
    }

    delete []leftArray;
    delete []rightArray;
}


void mergeSort(int *arr, int s, int e){

    if(s >= e)
        return;

    int mid = s + (e - s)/2;

    // left part pe apply kro
    mergeSort(arr,s,mid);

    // right part pe apply kro
    mergeSort(arr,mid+1,e);

    // merge both the arrays

    merge(arr,s,e);
}



int main(){

    int arr[12] = {12,45,63,89,23,46,72,13,27,30,55,78};
    //            12 13 23 27 30 45 46 55 63 72 78 89

    mergeSort(arr,0,12);

    for(int i = 0; i < 12; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}