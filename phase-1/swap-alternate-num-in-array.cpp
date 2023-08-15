#include <iostream>
using namespace std;

void swapAlternate(int arr[], int n){

    for(int i = 0; i < n; i = i + 2){
        if(i + 1 < n){
            int temp;
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    for (int i = 0; i< n; i++){
        cout<< arr[i]<<" ";
    }
}


int main(){

    int arr[7] = {1,2,3,4,5,6,7};
    swapAlternate(arr, (sizeof(arr)/sizeof(int)));
    cout<<endl<<sizeof(arr)/sizeof(int);

}