#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){

    vector<int> ans;
    int col = 0;

    while(col < mCols){

        if(col % 2 == 0){ // traverse from top to bottom

            for(int i = 0; i < nRows; i++){
                ans.push_back(arr[i][col]);
            }

        }
        else{ // traverse from bottom to top
            for(int i = nRows -1; i >= 0; i--){
                ans.push_back(arr[i][col]);
            }
        }
        col++;
    }
    return ans;
}



int main(){

    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans = wavePrint(vect,3,3);

    for(int i  = 0; i < ans.size(); i++){

        cout<<ans[i]<<" ";
    }
    cout<<endl;

    // for(int i = 0; i < 3; i++){

    //     for(int j = 0; j < 3; j++){
    //         cout<< vect[i][j]<<" ";
    //     }
    // }
}