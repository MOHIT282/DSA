// Given an array of size n, You have to find the maximum sum from every 3 consecutive elements of the array
#include <bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int n, int k){

    int wSum = 0;
    int i, max = INT_MIN;

    for(i = 0; i < k; i++){
        wSum += arr[i];
    }
    cout<<"Sum Inside window is : "<<wSum<<endl;
    if(max < wSum){
        max = wSum;
    }

    int j = 0;
    i = k-1;
    while(i < n-1){

        wSum = wSum -  arr[j];
        wSum = wSum + arr[i+1];
        if(max < wSum){
            max = wSum;
        }
        cout<<"Sum Inside window is : "<<wSum<<endl;
        i++;
        j++;
    }
    return max;
}


int main(){

    int arr[10] = {-12,2,4,-2,9,-6,1,0,4,-7};

    int max = findMaxSum(arr,10,2);

    cout<<"The max sum is : "<<max;

}