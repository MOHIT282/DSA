#include <bits/stdc++.h>
using namespace std;

int findPrice( vector<int> arr, int n, int m){

    sort(arr.rbegin(),arr.rend());

    for( int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int sum = 0;

    for(int i =0 ; i< arr.size();i++){
        if(i+1 != m){
            sum += arr[i];
        }
    }
    return sum;
}

int main(){

    vector<int> arr = {2, 3, 1, 5 };
    int ans = findPrice(arr,4,2);
    cout<<ans;

}