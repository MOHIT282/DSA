// Given are N boards of with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of the board. The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int size, int p, int mid){
    
    int boardCount = 0;
    int painters = 1;

    for(int i = 0; i< size; i++){

        if(boardCount + arr[i] <= mid){

            boardCount += arr[i];
        }
        else{
            painters++;
            if(painters > p || arr[i] > mid){
                return false;
            }
            boardCount = arr[i];
        }
    }
    return true;
}

int allocatePartition(int arr[], int size, int p){

    int totalBoards = 0;
    for(int i = 0; i < size; i++){
        totalBoards += arr[i];
    }

    int beg = 0;
    int end = totalBoards;
    int mid;
    int ans = -1;

    while(beg <= end){

        mid = beg + (end - beg)/2;

        if(isPossible(arr,size,p,mid)){
            ans = mid;
            end = mid -1;
        }
        else{
            beg = mid + 1;
        }
    }
    return ans;
}

int main(){

    int boards[] = {5,5,5,5};
    int ans = allocatePartition(boards,4,2);
    cout<<"Number of boards to be allocated per painter is : "<<ans<<endl;

}