#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        int i;
        int j;
    node(int data, int a, int b){
        this->data = data;
        i = a;
        j = b;
    }
};

class compare{
    public:
    bool operator()( node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector< vector<int>> Karrays, int k){

    // step 1 :- create a custom heap for ur needs
    priority_queue< node*, vector<node*>, compare > minHeap;

    // step 2 :- store the first element of each sub array in the minHeap
    for(int i = 0; i < k; i++){

        node* temp = new node(Karrays[i][0],i,0);
        minHeap.push(temp);
    }

    vector<int> ans;
    // push the next element of the array which has its first element on the top of the heap

    while(minHeap.size()>0){

        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < Karrays[i].size()){

            node* next = new node(Karrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main(){

    // vector<vector<int> > v ={
    //     {1,4,5,6,7,89,200},
    //     {3,56,87,90,101},
    //     {12,18,23,25,28,29,34},
    //     {34,35,37,39,41,47,50},
    //     {45,76,82,92}
    // };

    // vector<int> ans = mergeKArrays(v,5);

    // for(auto i : ans){
    //     cout<<i<<" ";
    // }cout<<endl;

    enum months {jan=2,feb=3,march=4};

    for(int i = jan; i <= march; i++){
        cout<<i<<" ";
    }

}