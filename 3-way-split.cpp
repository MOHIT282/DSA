#include <bits/stdc++.h>
using namespace std;


long long threeWaySplit(int n, vector<int> arr){
    
    int i = 0, j = n - 1;
    long long lsum = arr[i];
    long long rsum = arr[j];
    long long ans = 0;

    while(i < j){

        if(lsum == rsum){
            ans = lsum;
            i++;
            j--;
            lsum += arr[i];
            rsum += arr[j];
        }
        else if(lsum < rsum){
            i++;
            lsum += arr[i];
        }
        else{
            j--;
            rsum += arr[j];
        }
    }
    return ans;

}

int main(){

    vector<int> v = {28, 6, 12, 98, 46, 81, 26, 70, 59, 33, 21, 97, 18, 8, 21, 74, 19, 38, 13, 14, 19, 87, 71, 70, 42, 30, 28, 26, 60, 43, 28, 68,1, 49, 19, 50, 52, 68, 34, 92, 60, 55, 34, 41, 46, 18, 7, 28, 32, 87, 63, 70, 37, 50, 45, 29, 91, 66, 77, 62, 80, 38, 35, 89, 1, 4, 27, 27, 100, 69, 32};

    long long ans = threeWaySplit(71,v);
    cout<<ans<<endl; // 877

}