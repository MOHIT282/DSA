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
    node* top = new node(-1);
    node* head = new node(-1);

    void push(int data){
        node* temp = new node(data);

        if(head->next == NULL){
            head->next = temp;
            top = temp;
            
        }
        else{
            top->next = temp;
            top = temp;
        }
    }

    bool isEmpty(){
        return (head->next == NULL);
    }

    void pop(){
        if(top == head){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            node* ptr = head;

            while(ptr->next != top){
                ptr =  ptr->next;
            }
            ptr->next = NULL;
            top = ptr;
        }
    }

    int peek(){
        if(head->next == NULL){
            cout<<"The stack is empty"<<endl;
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