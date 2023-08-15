#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){

    bool swapped = false;
    for(int i = 0; i< n - 1; i++){

        for(int j = 0; j < n - i - 1; j++){

            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
                swapped = true;
        }
        if(!swapped)
            break;
    }
}



int main(){

    int arr[8] = {9,7,2,6,14,22,3,0};

    bubbleSort(arr, 8);

    for(int i = 0; i< 8; i++){
        cout<<arr[i]<<" "<<" ";
    }

}