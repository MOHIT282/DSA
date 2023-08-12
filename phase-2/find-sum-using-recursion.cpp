#include <bits/stdc++.h>
using namespace std;

int findSum(int arr[], int n){
    
    if(n == 0){
        return 0;
    }
    int ans = arr[0];
    ans += findSum(arr+1 , n-1);

    return ans;

}

int main(){

    int arr[] = {12,3,53,14,178,57,33};

    int ans = findSum(arr,7);

    cout<<ans;
}