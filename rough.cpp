#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string S, int K) {
        
        stack<char> st;
        string ans;
        
        for(int i = 0; i < S.length(); i++){
            
            char digit = S[i];
            
            while( K > 0 && st.size() && st.top() > digit){
                
                st.pop();
                K--;
            }
            st.push(digit); 
        }
        
        while(st.size() && K > 0){
            st.pop();
            K--;
        }
        // cout<<"st.size ->"<<st.size()<<endl;
        
        while(st.size()){
            
            ans.push_back(st.top());
            st.pop();
        }
        
        while(ans.size() && ans.back() == '0'){
            
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        
        if(ans.empty())  return "0";
        
        return ans;
    }

int main(){

    // if( "hello") cout<<"if loop worked";
    // if(int a = 34) cout<<"if loop again worked";
    // else cout<<"if loop doesn't worked";
    cout<< -6%5;

    // string str1 = "mohit";
    // string str2 = "kumar";
    
    // cout << (str1 < str2) <<endl;
}