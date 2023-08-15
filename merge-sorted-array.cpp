#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // n =3, m = 3 given in the question
    
        for(int i = m, j = 0; i<(m+n) && j< n; i++,j++){

            nums1[i] = nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }

int main(){

    vector<int> nums1 ={1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    merge(nums1, 3,nums2, 3);

    for(int i = 0; i < nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }

}