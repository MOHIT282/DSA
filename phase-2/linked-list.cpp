#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *link;

    node(int data){
        this->data = data;
        this->link = NULL;
    }

}*head = 0, *tail = 0;

void print(){

    node *ptr = head;

    while(ptr != NULL){
        cout<<ptr->data<<"  ";
        ptr = ptr->link;
    }
    cout<<endl;
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

    return 0;  

}