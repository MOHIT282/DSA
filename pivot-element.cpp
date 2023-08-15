#include <iostream>
using namespace std;

int findPivot(int arr[], int size){

    int beg = 0, end = size -1;
    int mid = beg + (end - beg)/2;

    while(beg < end){

        if( arr[mid] >= arr[end]){
            beg = mid + 1;
        }
        else{
            end = mid;
        }
        mid = beg + (end - beg)/2;
    }
    return mid;
}

int main(){

    int arr[7] = {4,5,6,7,0,1,2};
    cout<<"The pivot element is present at location : "<<findPivot(arr,10)<<" which is : "<<arr[findPivot(arr,10)]<<endl;

}