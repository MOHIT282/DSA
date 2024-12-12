/*
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6
1 ≤ target ≤ 10^6
 */


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countFreq(vector<int>& arr, int target) {
        
        int l = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int r = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        
        return r - l;
    }
    
};

int main(){

    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    Solution obj;
    cout<<obj.countFreq(arr, target)<<endl;

    return 0;

}