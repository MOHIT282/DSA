#include <bits/stdc++.h>
using namespace std;

int checkRedundancy(string s) {
        
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            
            char ch = s[i];
            
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                cout<<"value pushed in stack is : "<<ch<<endl;
                st.push(ch);
            }
            else if( ch == ')' ){
                
                if(st.top() == '('){
                    return true;
                }
                
                else{
                    
                    while(st.top() != '('){
                        cout<<"value popped out from stack is : "<<st.top()<<endl;
                        st.pop();
                    }
                    cout<<"value popped out from stack is : "<<st.top()<<endl;
                    st.pop();
                }
            }
        }
    return false;
}

int main(){

    string s = "(a + (b*c))";

    cout<<checkRedundancy(s)<<endl;
}