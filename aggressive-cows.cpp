#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int cows, int mid){

    int cowCount = 1;
    int lastPosition = stalls[0];
    for(int i = 0; i< stalls.size(); i++){

        if(stalls[i] - lastPosition >= mid){
            cowCount++;
            if(cowCount == cows){
                return true;
            }
            lastPosition = stalls[i];
        }
    }
    return false;
}

int allocateCowsPosition(vector<int> &stalls,int cows){

    sort(stalls.begin(),stalls.end());
    int maxValue = -1;
    for(int i = 0; i < stalls.size(); i++){

        maxValue = max(maxValue,stalls[i]);
    }
    int beg = 0,mid, ans = -1;
    int end = maxValue;
    while(beg <= end){

        mid = beg + (end - beg)/2;

        if(isPossible(stalls,cows,mid)){
            ans = mid;
            beg = mid +1;
        }
        else{
            end = mid -1;
        }
    }
    return ans;
}

int main(){

    vector<int> stalls = {4,2,1,3,6};
    cout<<"The maximum distance between the cows is : "<<allocateCowsPosition(stalls,3);

}