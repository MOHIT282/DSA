#include<bits/stdc++.h>
using namespace std;

void print(stack<int> st){

    while(!st.empty()){

        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

void pushBottom(stack<int> &st, int x){

    if(st.empty()){
        st.push(x);
        return;
    }

    int el = st.top();
    st.pop();

    pushBottom(st,x);
    st.push(el);
}

int main(){
    stack<int> st;

    st.push(6);
    st.push(2);
    st.push(8);
    st.push(4);
    st.push(3);

    print(st);
    pushBottom(st,5);
    print(st);
}