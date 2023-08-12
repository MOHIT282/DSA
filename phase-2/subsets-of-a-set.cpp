#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int index, vector<int> output, vector<vector<int>> &ans){

    if(index >= arr.size()){
        ans.push_back(output);
        return ;
    }
    
    // solve excluded part
    solve(arr,index+1,output,ans);

    // solve included part
    int element = arr[index];
    output.push_back(element);
    solve(arr,index+1, output, ans);

}


vector<vector<int>> findSubSets(vector<int> &arr){

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(arr,index, output,ans);

    return ans;
}

int main(){

    vector<int> v = {1,2,3};

    vector<vector<int>> ans = findSubSets(v);
  
    for(int i = 0; i < ans.size(); i++){

        for(int j = 0; j < ans[i].size(); i++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}