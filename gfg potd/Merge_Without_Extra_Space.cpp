/*
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays we get 5 10 12 18 20.
Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays we get 0 1 2 3.
Constraints:
1 <= a.size(), b.size() <= 105
0 <= a[i], b[i] <= 107
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        
        int i = a.size() - 1, j = 0;
          // swap smaller elements from b[] 
          // with larger elements from a[]
        while (i >= 0 && j < b.size() && a[i] > b[j]) {
              swap(a[i--], b[j++]);
        }
    
        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
    }
};

int main(){

    vector<int> a = {2, 4, 7, 10};
    vector<int> b = {2, 3};
    Solution obj;
    obj.mergeArrays(a, b);
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < b.size(); i++) cout << b[i] << " ";
    cout << endl;
    return 0;
}