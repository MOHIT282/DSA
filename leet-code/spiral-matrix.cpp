#include <bits/stdc++.h>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix){

    vector<int> ans;
    int count = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    int total = rows*cols;

    int startingRow = 0;
    int endingRow = rows - 1;
    int startingCol = 0;
    int endingCol = cols - 1;

    while(count < total){

        // for loop to traverse starting row
        for(int i = startingCol; count < total && i <= endingCol; i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // for loop to traverse last col
        for(int i = startingRow;count < total && i <= endingRow; i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // for loop to traverse the last row 
        for(int i = endingCol;count < total && i >= startingCol; i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // for loop to traverse the starting col
        for(int i = endingRow;count < total && i >= startingRow ; i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
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

    vector<int> ans1 = spiralOrder(vect);

    for(int i = 0; i < ans1.size(); i++){
        cout<<ans1[i]<<" ";
    }

}