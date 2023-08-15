#include <bits/stdc++.h> 
using namespace std;
vector<int> bitwiseAnd(int n, int q, vector<int> arr, vector<int> queries)
{
    vector<int> ans;
    int i= 0;
    
    while(i < q){

        int index = 0;
        int j = 1;
        int st = arr[0];
        if(st>= queries[i]){
            index = 1;
        }
        while(j < n){

            if( (st & arr[j]) >= queries[i]){
                index = j+1;
            }
            st = st & arr[j];
            j++;
        }
        ans.push_back(index);
       
        i++;
    }
    return ans;
}

int main(){
    
}