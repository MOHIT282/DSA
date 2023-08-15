#include <bits/stdc++.h>
using namespace std;

bool checkRotatedAndSorted(vector<int> & arr){

    int count = 0;
    int n = arr.size();
    for(int i = 1; i< n; i++){

        if(arr[i-1] > arr[i])
            count++;
    }
    if(arr[n-1] > arr[0])
        count++;

    // {1,1,1,1,1,} this is also a valid case in which count will not be incremented that's why if count = 0 still the ans can be true
    return count <= 1;
}

int main(){

    vector<int> arr = {3,4,5,1,2};
    cout<<(checkRotatedAndSorted(arr))<<endl;

    vector<int> arr2 = {2,1,3,4};
    cout<<(checkRotatedAndSorted(arr2))<<endl;

}