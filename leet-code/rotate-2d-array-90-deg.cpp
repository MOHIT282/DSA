#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix){

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> temp(rows, vector<int>(cols,0));

    int startingRow = 0;
    int endingRow = rows -1;

    int startingCol = 0;
    int endingCol = cols - 1;

    int count = 0 , total = rows * cols;

    while(count < total){

        // copying the starting Row in ending column
        for(int i = startingCol;count < total && i <= endingCol ; i++){
            temp[i][endingCol] = matrix[startingRow][i];
            count++;
        }
        startingRow++;

        //copying the ending Column with ending row
        for(int i = startingRow;count < total && i <= endingRow; i++){
            temp[endingRow][endingCol - i] = matrix[i][endingCol];
            count++;
        }
        endingCol--;

        // copying the ending Row in staring Col
        for(int i = endingCol;count < total && i>= startingCol;i--){
            temp[i][startingCol] = matrix[endingRow][i];
            count++;
        }
        endingRow--;

        //copying starting col in starting row
        for(int i = endingRow;count < total && i>= startingRow; i--){
            temp[startingRow][i - startingCol] = matrix[i][startingCol];
            count++;
        }
        startingCol++;
    }
    matrix = temp;

        // for rotating the array in anti-clock wise direction
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++)
            swap(matrix[i][j], matrix[j][i]);
    }

    int n = rows;
    int ind = n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[ind][i];
            matrix[ind][i] = temp;
            ind--;
        }
        ind = n - 1;
    }
}

int main(){

    // vector<vector<int>> vect = {
    //     {5,1,9,11},
    //     {2,4,8,10},
    //     {13,3,6,7},
    //     {15,14,12,16}
    // };
    vector<vector<int>> vect = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    rotate(vect);

    for(int i = 0; i < vect.size(); i++){

        for(int j = 0; j < vect[0].size(); j++){
            
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

    
}