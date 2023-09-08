#include<bits/stdc++.h>
using namespace std;


class Stack{

    public:
    deque<int> dq;

    int top(){

        return dq.back();
    }

    void push(int x){

        dq.push_back(x);
    }

    int pop(){
        if(dq.empty()) return -1;
        else return dq.back();
    }

    int size(){

        return dq.size();
    }
};



int main(){

    Stack st;
    st.push(54);
    cout<<st.pop();


}