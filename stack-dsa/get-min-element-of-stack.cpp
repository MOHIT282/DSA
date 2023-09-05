// geeksforgeeks question
#include<bits/stdc++.h>
using namespace std;


class Solution{
    int mini;
    stack<int> s;
    public:
    Solution(){ mini = INT_MAX;}
        
       int getMin(){
            if(s.empty()) return -1;
            return mini;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
            if(s.empty()) return -1;
            int val = 0;
            int curr = s.top();
            if(curr > mini){
                s.pop();
                val = curr;
            }
            else{
                val = mini;
                mini = 2 * mini - curr;
                s.pop();
            }
            return val;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           if(s.empty()){
               s.push(x);
               mini = x;
           }
           else if(x >= mini){
               s.push(x);
           }
           else{
               int val = 2 * x - mini;
               s.push(val);
               mini = x;
           }
       }
};


int main(){

    Solution sol;

    sol.push(5);
    sol.push(3);
    cout<<"Min value is : "<<sol.getMin()<<endl;

    sol.push(4);
    sol.push(1);
    cout<<"Min value is : "<<sol.getMin()<<endl;
    cout<<"value at top of stack is : "<<sol.pop()<<endl;
    sol.push(2);
    cout<<"Min value is : "<<sol.getMin()<<endl;

}