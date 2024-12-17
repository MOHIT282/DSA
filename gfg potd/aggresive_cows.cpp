/*
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
1 <= k <= stalls.size()
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& stalls, int k, int mid){

    int lastPosition = stalls[0];
    int cowCount = 1;
    for(int i = 0; i < stalls.size(); i++){

        if(stalls[i] - lastPosition >= mid){
            cowCount++;

            if(cowCount == k) return true;
            lastPosition = stalls[i];
        }
    }
    return false;
}

int aggresiveCows(vector<int>& stalls, int k){

    sort(stalls.begin(), stalls.end());

    int beg = 0, end = stalls[stalls.size()-1];
    int res = -1;
    while(beg <= end){

        int mid = beg + (end - beg)/2;

        if(isPossible(stalls,k, mid)){
            res = mid;
            beg = mid + 1;
        }
        else end = mid - 1;
    }

    return res;
}

int main(){

    vector<int> stalls = {1, 2, 4, 8, 9};
    cout<<"The maximum distance between the cows is : "<<aggresiveCows(stalls,3)<<endl;
    return 0;
}