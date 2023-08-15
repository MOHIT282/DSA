#include <bits/stdc++.h>
using namespace std;


bool binarySearch(int arr[], int size, int key){

    int beg = 0, end = size -1;
    int mid = end + (beg - end)/2;
    while(beg <= end){
        if( arr[mid] == key ){
            cout<<"Yes it is present at location : "<<mid<<endl;
            return true;
        }
        else if( arr[mid] > key){
            end = mid -1;  
            mid = (beg + end)/2;
        }
        else{
            beg = mid + 1;
            mid = (beg + end)/2;
        }
    }
    cout<<"The number is not present in the array";
    return false;
}

int main(){

    int arr[9] = {1,2,3,5,6,7,8,9,10};

    binarySearch(arr,10,10);

}