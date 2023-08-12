#include <bits/stdc++.h>
using namespace std;

int findSmallerElements(vector<vector<int>> &matrix, int assumedMid){  

    int smallerElements = 0;
    for(int i = 0; i < matrix.size(); i++){

        // applying binary search to find the smaller elements in each row
        int start = 0;
        int end = matrix[i].size() - 1;
        int mid;

        while(start <= end){
            mid = start + (end - start)/2; 

            if(matrix[i][mid] <= assumedMid){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        smallerElements = smallerElements + start;
    }
    return smallerElements;
}

int findMedian(vector<vector<int>> &matrix, int R, int C){

    int N = R * C;
    int median = N / 2;

    int l = 0;
    int h = 100000; // maximum element of a matrix can be <= 2000 as given in the constraints

    int mid;

    while(l <= h){

        mid = l + (h - l)/2;
        int smallerElements = findSmallerElements(matrix, mid);
        cout<<"The assumed median is "<<mid<<" and values smaller are "<<smallerElements<<endl;
        if( smallerElements <= median){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }    
    }
    return l;
}

int main(){

    vector<vector<int>> v =
    {
        {2, 6, 9},
        {1, 5, 11},
        {3, 7, 8}
    };

    int median = findMedian(v,v.size(),v[0].size());

    cout<<"The midean of matrix is : "<<median;
}


