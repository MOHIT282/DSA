#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){

    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;  
    // we are starting from 15. Now the  question arises is why 15?
    // the answer to it is that if a number is higher than 15 it will definately not be in that row(i.e left of 15 so we have to go down by using row++) and if a number is less than 15 it will not be in its column (i.e down of 15 so we have to go left i.e. col--)
    // we can apply this same logic for 18 as well 
    while(rowIndex < row && colIndex >=0){

        int element = matrix[rowIndex][colIndex];

        if(element == target){
            return 1; // true
        }
        else if(element < target){
            rowIndex++;
        }
        else{
            colIndex--;
        }
    }
    return 0; // false;
}




int main(){

    vector<vector<int>> vect =
    {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    cout<<searchMatrix(vect,5);

}