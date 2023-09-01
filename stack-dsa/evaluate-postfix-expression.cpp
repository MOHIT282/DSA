#include<bits/stdc++.h>
using namespace std;

int calculate(int op1, int op2, char ch){
        
    if(ch == '+') return (op1 + op2);
    if(ch == '-') return (op1 - op2);
    if(ch == '*') return (op1 * op2);
    if(ch == '/') return (op1 / op2);
}
    
    int evaluatePostfix(string s)
    {
        stack<int> st;
        
        for(int i = 0; i < s.length(); i++){
            
            char ch = s[i];
            
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();
                
                st.push( calculate(val1, val2, ch));
            }
            else{
                
                int val = ch - '0';
                st.push(val);
            }
        }
        return st.top();
    }


int main(){

    string str = "231*+9-";
    cout<<"Answer is : "<<evaluatePostfix(str); 
  
}