#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int totalDish, int target){

    int dishes = 0;
    int n = arr.size();
    int time = 0;
    
    for(int i = 0; i < n; i++){

        int nextDishTime = 1;
        time = 0;
        
        while(time + arr[i]*nextDishTime  <=  target){
            time += arr[i]*nextDishTime;
            dishes++;
            nextDishTime++;
        }
        if(dishes >= totalDish){
            return true;
        }

    }
    return false;
}



int minCookTime(vector<int> &rank, int m)
{
    int n = rank.size();
    int start = 0;
    int end = 1e9;
    int mid,ans = -1;

    while(start <= end){
        mid = start + (end - start)/2;

        if(isPossible(rank,m,mid)){
            ans = mid;
            end = mid -1 ;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}


int main(){

    vector<int> rank = {1,2,3,4};

    int ans = minCookTime(rank,11);

    cout<<ans;
    
}