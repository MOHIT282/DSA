#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;
    
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void buildTree(node* &root){

    int data;
    cout<<"Enter the node data : ";
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter the data in left of "<<temp->data<<" : ";
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter the data in right of "<<temp->data<<" : ";
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void preorderTraversal(node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(node* root){

    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void postorderTraversal(node* root){

    if(root == NULL){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

void topOrderView(node* root){

    vector<int> ans;
    map<int, int > mp;
    queue< pair<node*, int> >  q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;

        if(mp.find(hd) == mp.end())
            mp[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right)
            q.push(make_pair(frontNode->right,hd+1));
    }

    for(auto i : mp){
        ans.push_back(i.second);
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main(){

    node *root;
    buildTree(root);
    cout<<endl<<"Inorder Traversal : ";inorderTraversal(root);
    cout<<endl<<"Preorder Traversal : ";preorderTraversal(root);
    cout<<endl<<"Postorder Traversal : ";postorderTraversal(root);
    cout<<endl<<"Top order View : ";topOrderView(root);
}