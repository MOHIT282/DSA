#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int size = 0;
        for(int i=0; i< n-2; i++){
            int j = i+1, k= n-1;
            int target = 0 - nums[i];
            while( j<k){

                vector<int> temp;
                if(nums[j]+ nums[k] > target){
                    k--;
                }
                else if(nums[j]+ nums[k] < target){
                    j++;
                }
                else if(nums[j]+ nums[k] == target){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }




int main(){


    while(true){
        cout<<"allocating new memory in heap"<<endl;
        int *p = new int;
    }

}