#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high){

    int pivot = arr[low];
    int k = high;

    for(int i = high; i > low; i--){

        if(arr[i] > pivot){

            swap(arr[i], arr[k]);
            k--;
        }
    }
    swap(arr[low],arr[k]);
    return k;
}

void quickSort(int *arr, int low, int high){

    if( low > high) return;

    int p = partition(arr, low, high);

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);

}

int main(){

    int arr[] = {12, 34, 12, 5, 35, 89, 478, 56, 22, 89};

    quickSort(arr,0,9);

    for(int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}