#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(){}

    node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~node(){
        cout<<"Deleted the node at value : "<<this->data<<endl;
    }

}*tail=0,*head = 0;

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

    node * ptr = head;

    do{
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    while(ptr != head);
    cout<<endl;
    // delete ptr;
}

void insertNode(int d){

    node *temp = new node(d);

    if(tail == 0 && head == 0){
        temp->next = temp;
        head = temp;
        tail = temp;
        return;
    }
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
}


int main(){

    insertNode(10);
    print();
    insertNode(20);
    print();
    insertNode(30);
    print();
    insertNode(40);
    print();
    insertNode(50);
    print();
    insertNode(60);
    print();
}