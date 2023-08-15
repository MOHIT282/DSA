#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, vector<vector<int>> &arr, int B, int mid){

    int candies = 0;
    int friendCount = 1;

    for(int i = 0; i< n; i++){

        for(int j = 0; j< arr[i].size(); j++){

            if(arr[i][j] <= mid && friendCount <= n){
                candies += arr[i][j];
            }
        }
        if(candies > B || friendCount > n){
            return false;
        }
        friendCount++;
    }
    return true;

}

int findMaxX(int n, vector<vector<int>> &arr, int B){

    int beg = 0,sum = 0;
    int end = 0;
    int mid, ans = 0;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 1; j <= arr[i][0]; j++)
        {
            sum += arr[i][j];
        }
        end = max(end, sum);
    }
    
    while(beg<=end){

        mid = beg + (end - beg)/2;

        if(isPossible(n,arr,B,mid)){
            ans = mid;
            beg = mid+1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}



int main(){

    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 2, 3},
        {1, 10, 2}
    };

    int ans = findMaxX(3,vect,20);
    cout<<ans<<endl;
  
}