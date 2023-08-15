#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){

    for(int i = 0; i< size; i++){
        cout<<arr[i]<<"  ";
    }
}

int findPeakElement(int arr[], int size){

    int beg = 0, end = size -1;
    int mid = beg + (end - beg)/2;

    while( beg < end){
        
        if(arr[mid] < arr[mid + 1]){
            beg = mid + 1;
        }
        else{
            end = mid;
        }
        mid = beg + (end - beg)/2;
        // cout<<"hello"<<endl;
    }
    return beg;

}

int main(){

    int arr[10] = {1,2,3,4,5,22,63,6,3,1};
    int peakValue = findPeakElement(arr,10);
    cout <<"The peak value is present at location "<< peakValue<<" which is : "<<arr[peakValue] << endl;

}