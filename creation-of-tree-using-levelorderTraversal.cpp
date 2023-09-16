#include<bits/stdc++.h>
using namespace std;


class node{

    public:
    int data;
    node *left, *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


void levelOrderTraversalTree(node* &root){

    queue<node*> q;
    cout << "Enter the root data : ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){

        node *temp = q.front();
        q.pop();

        cout << "Enter the left of "<<temp->data<<" : ";
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right of "<<temp->data<<" : ";
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void InorderTraversal(node *root){

    if(root == NULL) return;

    InorderTraversal(root->left);
    cout<<root->data<<" ";
    cout<<"Inorder Traversal of the tree is : ";
    InorderTraversal(root->right);
}



int main(){

    node* root = NULL;
    levelOrderTraversalTree(root);
    InorderTraversal(root);
}