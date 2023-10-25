#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* partition(node* head, node* end){
    
    if(head == end) return head;
    
    node* temp = head->next;
    node* pivot = head;
    
    while(temp != end){
        
        if(head->data > temp->data) pivot = pivot->next;
        
        temp = temp->next;
    }
    cout<<"Pivot's correct Position is at : "<<pivot->data<<endl;
    if(head != pivot) swap(head->data, pivot->data);

  
    node* temp1 = head;
    node* temp2 = pivot->next;
    
    while(temp1 != pivot && temp2 != end){
        
        while(temp1 != pivot && temp1->data < pivot->data) temp1 = temp1->next;
        cout<<"Value greater than pivot : "<<temp1->data<<endl;

        while(temp2 != end && temp2->data > pivot->data ) temp2 = temp2->next;
        cout<<"Value smaller than pivot"<<temp2->data<<endl;
        
        if(temp1 != pivot && temp2 != end){
            swap(temp1->data, temp2->data);
            cout<<"Swapping done"<<endl;
        }
    }
    cout<<"Returning by doing partition"<<endl;
    return pivot;
}

void helper(node * head, node* end){
    
    if(head == NULL || head->next == NULL || head == end){
        cout<<"Returning from quickSort"<<endl;
        return;
    }
    
    node* pivot = partition(head, end);
    cout<<"pivot element is :"<<pivot->data<<endl;
    
    helper(head, pivot);
    
    if(pivot->next) helper(pivot->next, end);
    
}

void quickSort(node* head) {
    
    helper(head, NULL);
}

void insertAtTail(node* &root, int data){

    if(root == NULL){
        root = new node(data);
        return;
    }

    node * temp = new node(data);
    root->next = temp;
    root = root->next;
}

void print(node* root){

    while(root){
        cout<<root->data<<" ";
        root = root->next;
    }cout<<endl;
} 


int main(){
     
    node* head = new node(10);
    node* tail = head;

    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    insertAtTail(tail, 3);
    insertAtTail(tail, 18);

    cout<<"before Quick Sort --> ";
    print(head);

    quickSort(head);

    cout<<"After Quick Sort -->";
    print(head);

}