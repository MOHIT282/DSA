#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long int arr[],int n,long long int m, long long int mid){

    long long int reqdWood = 1;

    for(int i = 0; i< n; i++){
        
        if(arr[i] >= mid){
            reqdWood += arr[i] - mid;
        }
    }
    if(reqdWood > m){
        return true;
    }
    else{
        return false;
    }
}

long long int getTreeHeight(long long int arr[], long long int n,long long int m){

    long long int maxHeight = -1;
    for(int i = 0; i< n; i++){
        maxHeight = max(maxHeight,arr[i]);
    }

    int beg = 0;
    long long int end = maxHeight;
    long long int mid;
    long long int answer = -1;

    while(beg <= end){

        mid = beg + (end - beg)/2;

        if(isPossible(arr,n,m,mid)){
            answer = mid;
            beg = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return answer;
}

int main(){

    long long int arr[] = {20, 15, 10, 17,25};
    cout<<"The height of the cutter should be : "<<getTreeHeight(arr,5,7)<<endl;

}