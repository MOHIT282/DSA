#include <iostream>
using namespace std;


class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class queue{

    public:
    Node* front;
    Node* rear;

    queue(){ front = NULL; rear = NULL;}

    void push(int data){
        Node* temp = new Node(data);

        if(front == NULL && rear == NULL){
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int pop(){

        if(front == NULL){
            return -1;
        }
        int data = front->data;
        front = front->next;
        return data;
    }

    bool isEmpty(){
        if(front == rear) return true;
        return false;
    }

    int front_ele(){
        if(front == NULL) return -1;
        return front->data;
    }

    int rear_ele(){

        if(rear == NULL) return -1;
        return rear->data;
    }

    void print(){
    
        Node* temp = front;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};


int main(){

    queue q;
    cout<<"Is Queue Empty -->"<<q.isEmpty()<<endl;
    q.push(1);
    q.print();
    q.push(2);
    q.print();
    q.push(3);
    q.print();
    q.push(4);
    q.print();
    q.pop();
    q.print();
    cout<<q.front_ele()<<endl;
    cout<<q.rear_ele()<<endl;
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    cout<<q.pop()<<endl;
    cout<<"Is Queue Empty -->"<<q.isEmpty()<<endl;
}