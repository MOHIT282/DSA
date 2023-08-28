#include<bits/stdc++.h>
using namespace std;


vector<int> next_smaller(vector<int> arr, int n) 
    { 
    vector<int> ans;
    stack<int> st;
        
    st.push(-1);
        
    for(int i = n-1; i>= 0; i--){
    
        if(st.top() < arr[i]){
            ans.insert(ans.begin(), st.top());
            cout<<"Value pushed -->"<<arr[i]<<endl;
            st.push(arr[i]);
        }
        else{
            
            while(st.top() >= arr[i]){
                cout<<"value popped -->"<<st.top()<<endl;
                st.pop();
            }
            ans.insert(ans.begin(), st.top());
            cout<<"Value pushed -->"<<arr[i]<<endl;
            st.push(arr[i]);
        }
    }
    return ans;
}


int main(){

    vector<int> v ={2, 5, 3, 7, 1, 5, 2, 6, 3, 1};

    vector<int> ans = next_smaller(v,v.size());


    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}