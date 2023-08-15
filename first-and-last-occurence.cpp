#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int size, int key){

    int beg = 0, end = size -1;
    int mid = end + (beg - end)/2;
    int ans = -1;

    while(beg <= end){
        if( arr[mid] == key ){
            end = mid - 1;
            ans = mid;
        }
        else if( arr[mid] > key){
            end = mid -1;  
        }
        else{
            beg = mid + 1;
        }

        mid = end + (beg - end)/2;

    }
    return ans;
}

int lastOccurence(int arr[], int size, int key){

    int beg = 0, end = size -1;
    int mid = end + (beg - end)/2;
    int ans = -1;

    while(beg <= end){
        if( arr[mid] == key ){
            ans = mid;
            beg = mid + 1;
        }
        else if( arr[mid] > key){
            end = mid -1;  
        }
        else if(arr[mid] < key){
            beg = mid + 1;
        }

        mid = end + (beg - end)/2;

    }
    return ans;
}



int main(){

    int arr[12] = {1,3,4,5,5,5,5,5,8,12,19,20};

    int firstOccur = firstOccurence(arr,12,5);
    int lastOccur = lastOccurence(arr,12,5);

    cout<<"First occurence of 5 is at loc : "<< firstOccur<<endl;
    cout<<"Last occurence of 5 is at loc : "<< lastOccur<<endl;
}