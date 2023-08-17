#include<iostream>
using namespace std;

class node{

    public:
        int data;
        node* next;

        node(int data = 0){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{

    public:
    node* top;

    Stack() { top == NULL;}

    void push(int data){
        node* temp = new node(data);

        temp->next = top;
        top = temp;
    }

    bool isEmpty(){
        return (top == NULL);
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top = top->next;
        }
    }

    int peek(){
        if(top == NULL){
            return -1;
        }
        else{
            return top->data;
        }
    }
};

int main(){


    Stack st;

    cout<<st.isEmpty()<<endl;
    st.push(8);
    st.push(9);
    cout<<"Element present at top of the stack is : "<<st.peek()<<endl;
    st.pop();
    cout<<"Element present at top of the stack is : "<<st.peek()<<endl;
    st.pop();
    st.push(34);
    cout<<"Element present at top of the stack is : "<<st.peek()<<endl;
    st.pop();
    cout<<st.isEmpty()<<endl;
}