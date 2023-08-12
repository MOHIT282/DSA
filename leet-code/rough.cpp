#include <bits/stdc++.h>
using namespace std;

int findSmallerElements(vector<vector<int>> &matrix, int assumedMedian){
    int smallerElements = 0;
    for(int i = 0; i<matrix.size(); i++){

        int beg = 0;
        int end = matrix[i].size()-1;
        int mid;

        while(beg <= end){

            mid = beg + (end - beg)/2;

            if(matrix[i][mid] <= assumedMedian){
                beg = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        smallerElements += beg;
      
    }
    return smallerElements;
}


int getMedian(vector<vector<int>> &matrix)
{
   int low = 1;
   int high = 100000;
   int median = (matrix.size()*matrix[0].size())/2;
   cout<<"Median "<<median<<endl;
   int mid;

   while(low <= high){
       mid = low + (high - low)/2;
       int smallerElements = findSmallerElements(matrix, mid);
       cout<<"The assumed median is "<<mid<<" and values smaller are "<<smallerElements<<endl;
       if(smallerElements <= median){
           low = mid + 1;
       }
       else{
           high = mid - 1;
       }
    }
    return low;
}


int main(){

vector<vector<int>> v =
    {
        {2},
{4},
{1},
{3},
{5}
    };

    int median = getMedian(v);

    cout<<"The midean of matrix is : "<<median;
}