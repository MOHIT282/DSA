#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& arr, int n) {
        

    vector<int> temp(n+1,0);

    for(int i = 0; i < n-1; i++){

        temp[arr[i]] = 1;
    }

    for(int i = 0; i < n; i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    for(int i = 1; i < temp.size(); i++){

        if(temp[i] == 0){
            return i;
        }
    }
}

int main(){

    vector<int> v =  {1,2,3,5,7,4};

    int ans = missingNumber(v,v.size()+1);

    cout<<ans;

    
    

}