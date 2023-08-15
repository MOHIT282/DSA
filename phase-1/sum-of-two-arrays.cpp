#include <bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m){
    int i= 0, j = 0;
    int ans1= 0, ans2 = 0;
    vector<int> ans;

    while(i<n){

        ans1 = (ans1*10) + a[i++];
    }

    while(j<m){

        ans2 = (ans2*10) + b[j++];
    }

    ans1 += ans2;

    while(ans1 != 0){
        int temp;
        temp = ans1 % 10;
        ans.push_back(temp);
        ans1 = ans1/10;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

    vector<int> a ={4,5,1};
    vector<int> b ={3,4,5};

    vector<int> ans = findArraySum(a,3,b,3);

    for(int i = 0; i< ans.size(); i++){
        cout<<ans[i]<<" ";
    }
} 