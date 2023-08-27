#include <bits/stdc++.h>
using namespace std;

bool valid(string s)
{
    int size = s.length();
    stack<char> st;
    
    for(int i = 0; i < size; i++){
        
        char ch = s[i];
        
        if( (ch == '(') || (ch == '[') || (ch == '{') ){
            cout<<"Push operation -->"<<ch<<endl;
            st.push(ch);
            continue;
        }

        if(st.empty()){
            return 0;
        }
        char top = st.top();
        
        
        if( ( ch == ')' && top == '(' ) || (ch == '}' && top == '{' ) || (ch == ']' && top == '[')){
            cout<<"Pop operation -->"<<ch<<" and top -->"<<top<<endl;
            st.pop();
        }
        else{
            return false;
        }
    }

    return st.empty();
}

int main(){

    string brackets = "((((";
    cout<<valid(brackets)<<endl;
}