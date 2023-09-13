#include<bits/stdc++.h>
using namespace std;

class Queue{

    public:
    int front,rear,size;
    int *arr;

    Queue(int n = 10){
        front = -1;
        rear = -1;
        size = n;
        arr = new int[size];
    }

    void push(int x){

        if(front == 0 && rear == size - 1 || rear == front - 1){
            cout<<"Queue is full already"<<endl;
        }
        else if(front == -1){ // queue is empty
            front = 0;
            rear = 0;
            arr[rear] = x;
        }
        else if(front != 0 && rear == size - 1 ){
            rear = 0;
            arr[rear] = x;
        }
        else{
            rear++;
            arr[rear] = x;
        }
    }

    void pop(){

        if(front == -1){
            cout<<"Queue is empty already"<<endl;
        }
        else if(front == rear ){
            front = -1;
            rear = -1;
        }
        else if(front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
    }
};



int main(){

    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.pop();
    // cout<<"front is at : "<<q.front<<endl;
    // cout<<"Rear is at : "<<q.rear<<endl;
    q.push(6);
    q.push(7);
    // q.push(8);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<"front is at : "<<q.front<<endl;
    cout<<"Rear is at : "<<q.rear<<endl;
    // cout<<"Front is at : "<<q.arr[q.front]<<endl;
    // cout<<"Rear is at : "<<q.arr[q.rear]<<endl;
}