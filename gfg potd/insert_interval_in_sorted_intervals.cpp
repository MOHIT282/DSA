/*
Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.

Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:

Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
Output: [[1,3], [4,7], [8,10]]
Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].
Input: intervals = [[1,2], [3,5], [6,7], [8,10], [12,16]], newInterval = [4,9]
Output: [[1,2], [3,10], [12,16]]
Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Constraints:
1 ≤ intervals.size() ≤  105
0 ≤ start[i], end[i] ≤ 109
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>>&res, vector<int>& interval){
    if(res.empty() || res.back()[1] < interval[0]){
        res.push_back(interval);
    }
    else{
        res.back()[1] = max(res.back()[1], interval[1]);
    }
}

int main(){

    vector<vector<int>> intervals = {{1,5}};

    vector<int> newInterval = {0,3};

    vector<vector<int>> res;
    bool inserted = false;

    int i = 0;

    // while(i < intervals.size()){

    //     vector<int> interval = intervals[i];

    //     if(!inserted and interval[0] > newInterval[0]){

    //         merge(res, newInterval); // merge the new interval with the first interval if necessary
    //         inserted = true;
    //     }

    //     else{

    //         if(res.size() and res.back()[1] >= interval[0]){

    //             res.back()[1] = max(res.back()[1], interval[1]); // merge overlapping intervals if necessary
    //         }
    //         else res.push_back(interval);
    //         i++;
    //     }
    // }

    // if(!inserted) merge(res, newInterval); // if the new interval is not inserted, then insert it

    // for( auto i : res) cout<<i[0]<<" "<<i[1]<<endl; // print the result

    cout<<((-4 % 2) != 0)<<endl;

    return 0;

}