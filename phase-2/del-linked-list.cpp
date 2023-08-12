#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *link;

    node(int d){
        this->data = d;
        this->link = NULL;
    }

    ~node(){
        int val = this->data;
        cout<<"the destructor have been called for the value : "<<val<<endl;
    }

}*head , *tail;


void print(){

    node *ptr = head;

    while(ptr != NULL){
        cout<<ptr->data<<"  ";
        ptr = ptr->link;
    }
    cout<<endl;
    // cout<<"head is pointing at : "<<head->data<<endl;
    // cout<<"tail is pointing at : "<<tail->data<<endl<<endl;
}

void deleteNodeAtPosition(int pos){

    node *temp = head;
    node *prev;
    int cnt = 1;

    // if first node is to be deleted
    if(pos == 1){
        head = head->link;
        return;
    }
    
    while(cnt < pos){
        prev = temp;
        temp = temp->link;
        cnt++;
    }
    cout<<"temp is at : "<<temp->data<<endl<<"prev is at : "<<prev->data<<endl;

    // handling the deleting of a last node
    if(temp->link == 0){
        prev->link = 0;
        tail = prev;
    }
    else{
        prev->link = temp->link;
        temp->link = 0;
    }

}

void insertNodeatHead(int d){

    node *temp = new node(d);
    temp->link = head;
    head = temp;
}

void insertNodeAtTail(int d){

    node *temp = new node(d);
    tail->link = temp;
    temp->link = 0;
    tail = temp;
    
}

void insertAtAPosition(int pos,int d){

    // for inserting at the first position
    if(pos == 1){
        insertNodeatHead(d);
        return;
    }
    int cnt = 1;

    node *temp = head;

    while(cnt < pos-1){
        temp = temp->link;
        cnt++;
    }

    // for inserting at the end of the linked list
    if(temp->link == NULL){
        insertNodeAtTail(d);
        return;
    }

    node *nodeToInsert = new node(d);
    nodeToInsert->link = temp->link;
    temp->link = nodeToInsert;
}

int main(){

    node *n1 = new node(20);

    // print(head);
    head = tail = n1; 

    insertNodeAtTail(30);
    print();

    insertNodeAtTail(40);
    print();

    insertNodeAtTail(50);
    print();

    insertAtAPosition(1,3566);
    print();

    deleteNodeAtPosition(5);
    print();

    return 0;  

}