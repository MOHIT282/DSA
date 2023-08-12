#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node * prev;
    node * next;

    node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

}*head, *tail;

void headTailLoc(){
    cout<<endl<<endl<<"Head is at : "<<head->data<<" and Tail is at : "<<tail->data<<endl;
}

int getLength(){

    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void print(){
    
    node *temp = head;

    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(int data){
    
    node *temp = new node(data);

    if(head == 0){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = head->prev;
    }

  
}

void insertAtTail(int data){

    node *temp = new node(data);

    if(head == 0){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void insertAtPosition(int pos,int data){

    node *ptr = head;
    int cnt = 1; // as the pointer will point the first node 

    if(pos == 1){ // if user wants to insert at first place

        insertAtHead(data);
        return;
    } 

    while (cnt < pos -1)
    {
        ptr = ptr->next;
        cnt++;
    }

    if(ptr->next == 0){
        insertAtTail(data);
        return;
    }

    node *temp = new node(data);
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;

    delete ptr;
}

void deleteNode(int pos){

    node *ptr = head;
    node *previous;
    
    // for deleting first node
    if(pos == 1){
        head = head->next;
        head->prev = 0;
        ptr->next = 0;
        delete ptr;
        return;
    }

    int cnt = 1;

    while(cnt < pos){
        previous = ptr;
        ptr = ptr->next;
        cnt++;
    }

    // if last node is to be deleted

    if(ptr->next == 0){
        tail = ptr->prev;
        tail->next = 0;
        ptr->prev = 0;
        delete ptr;
        return;
    }
    previous->next = ptr->next;
    ptr->prev = ptr->next = 0;

    delete ptr;
    // delete prev;
}


int main(){

    // node *n1 = new node(10);
    // head = tail = n1;
    insertAtTail(10);
    print();
    insertAtTail(20);
    print();
    insertAtTail(30);
    print();
    insertAtTail(40);
    print();
    insertAtTail(50);
    print();
    insertAtTail(60);
    print();

    cout<<"Inserting a position 4 with value 35 "<<endl;
    insertAtPosition(7,70);
    print();

    deleteNode(7);
    print();

    cout<<"The lenght of the linked list is : "<<getLength();
    headTailLoc();
}