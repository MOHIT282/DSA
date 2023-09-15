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

void preorderTraversal(node* root){

    if(root == NULL){
        cout<<"Tree doesn't exists";
        return; 
    }
    stack<node*> st;

    node* curr = root;

    while(curr || !st.empty()){

        while(curr){

            cout<<curr->data<<" ";

            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        curr =  curr->right;
    }
}


void inorderTraversal(node* root){

    if(root == NULL){
        cout<<"Tree doesn't exists";
        return;
    }
    stack<node*> st;

    node* curr = root;

    while(curr || !st.empty()){

        while(curr){

            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";

        curr = curr->right;
    }
    
}

void postOrderTraversal(node* root){

    if(root == NULL){
        cout<<"Tree doesn't exissts"<<endl;
        return;
    }

    stack<node*> st;
    node*  curr = root;

    st.push(NULL);

    while(curr || !st.empty()){

        while(curr){

            if(curr->right) st.push(curr->right);

            st.push(curr);

            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        if(curr->right && (curr->right == st.top() )){
            node* temp = st.top();
            st.pop();
            st.push(curr);
            curr = temp;
        }
        else{
            cout<<curr->data<<" ";
            curr = NULL;
        }
    }
}

int main(){
    node *root;
    root = BinaryTree(root);
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
}