#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m){

    int max = INT_MIN;
    int maxRow;
    int index = -1;
    for(int i = 0; i < n; i++){

        maxRow = count(arr[i].begin(), arr[i].end(),1);
        if(maxRow > max && maxRow > 0){
            max = maxRow;
            index = i;
        }
    }

    return index;

}

int main(){

    vector<vector<int>> v = 
    {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}};

    int ans = rowWithMax1s(v,4,4);

    cout<<ans;

}