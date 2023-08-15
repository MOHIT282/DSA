#include <bits/stdc++.h>
using namespace std;


void selectionSort(int arr[], int n){

    for(int i = 0; i < n-1; i++){

        int minIndex = i;

        for(int j = i+1; j < n; j++){

            if(arr[j]< arr[minIndex]){

                minIndex = j;
            }
        }
        // swapping the ith element with the smallest element present at minIndex
        if(i != minIndex)
            swap(arr[i],arr[minIndex]);
    }

}


int main(){

    int arr[] = {1,23,15,12,43};
    selectionSort(arr,5);
    cout<<"The array after sorting is : ";
    for(int i = 0; i< 5; i++){
        cout<<arr[i]<< " ";
    }

}