#include <bits/stdc++.h>
using namespace std;

void sortArr(int arr[], int n){

    sort(arr,arr+n);

}

int main(){
    int arr[] = {2,3,9,2,2};
    sortArr(arr,5);

    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
}