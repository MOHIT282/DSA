#include<bits/stdc++.h>
using namespace std;


class node{

    public:
    int data;
    node *left, *right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* BinaryTree(node* root){

    int data;
    cout<<"Enter the data : ";
    cin>>data;
    root = new node(data);

    if(data == -1) return NULL;

    cout<<"Insert a node in the left of "<<data<<endl;
    root->left = BinaryTree(root->left);
    cout<<"Insert a node in the right of  "<<data<<endl;
    root->right = BinaryTree(root->right);

    return root;
}

void InorderTraversal(node* root){

    if(root == NULL) return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

void PreorderTraversal(node* root){

    if(root == NULL) return;

    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void PostorderTraversal(node* root){

    if(root == NULL) return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){

    node *root;
    root = BinaryTree(root);
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    cout<<"Inorder Traversal : ";InorderTraversal(root);
    cout<<endl<<"Preorder Traversal : ";PreorderTraversal(root);
    cout<<endl<<"Postorder Traversal : ";PostorderTraversal(root);
}