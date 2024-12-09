/*
Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.
Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non overlapping.
Constraints:
1 ≤ intervals.size() ≤  10^5
|intervals[i]| == 2
0 ≤ starti < endi <=5*10^4

question url = https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:

    static bool compare(vector<int>&a, vector<int>& b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int minRemoval(vector<vector<int>> &intervals) {

        // intervals = [[1, 19], [5, 10], [18, 35], [40, 45]]; output = 1
        sort(intervals.begin(), intervals.end(), compare);
        
        int res = 0, prev = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            
            if(intervals[i][0] < intervals[prev][1]){
                res++;
            }
            else prev = i;
        }
        
        return res;
    }
};


int main(){

    vector<vector<int>> intervals = {{1, 5}, {2, 3}, {3, 4}, {1, 3}};

    Solution obj;
    int ans = obj.minRemoval(intervals);

    cout<<ans;

}