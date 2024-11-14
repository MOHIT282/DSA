/*
Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

Example 1:

Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}
Output: 4
Explanation:
Optimal Split is {1, 2}, {3}, {4}.
Maximum sum of all subarrays is 4,
which is minimum possible for 3 splits. 
Example 2:

Input:
N = 3, K = 2
A[] = {1, 1, 2}
Output:
2
Explanation:
Splitting the array as {1,1} and {2} is optimal.
This results in a maximum sum subarray of 2.
Your Task:
You do not have to take any input or print anything. The task is to complete the function splitArray() which returns the maximum sum subarray after splitting the array into K subarrays such that maximum sum subarray is minimum possible.

Expected Time Complexity: O(N*log(sum(arr))).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ N
1 ≤ arr[i] ≤ 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool helper(int arr[], int n, int k, int allowedSum){

        int groups = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){

            if(sum + arr[i] <= allowedSum) sum += arr[i];

            else{
                groups++;
                sum = arr[i];
                if(groups > k || arr[i] > allowedSum) return false;
            }
        }
        return true;
    }
    
    int splitArray(int arr[] ,int n, int K) {
        
        int low = INT_MIN, high;

        for(int i = 0; i < n; i++){

            high += arr[i];
            if(low < arr[i]) low = arr[i];
        }
        
        int mid, ans = -1;
        while(low <= high){

            mid = low + (high - low)/2;

            bool isPossible = helper(arr, n, K, mid);

            if( isPossible ){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }
        return ans;
    }
};

int main(){

    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Solution obj;
    cout<<obj.splitArray(arr, 10, 3);
}