/*
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;
};

Node* newNode(int data){

    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

class Solution
{
    public:
    
    Node* reverse(Node* head){
        
        Node* curr = head;
        Node* aage;
        Node* piche = NULL;
        
        while(curr){
            
            aage = curr->next;
            curr->next = piche;
            piche = curr;
            curr = aage;
        }
        return piche;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node * temp = newNode(-1);
        
        Node* curr1 = node1;
        Node* curr2 = node2;
        Node* tail = temp;
        
        while(curr1 != NULL && curr2 != NULL){
            
            if(curr1->data < curr2->data){
                
                tail->next = curr1;
                tail = tail->next;
                curr1 = curr1->next;
            }
            
            else{
                
                tail->next = curr2;
                tail = tail->next;
                curr2 = curr2->next;
            }
        }
        if(curr1){
            tail->next = curr1;
        }
        else if(curr2){
            tail->next = curr2;
        }
        return reverse(temp->next);
    }  
};


int main(){



}