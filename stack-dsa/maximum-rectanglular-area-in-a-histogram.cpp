#include<bits/stdc++.h>
using namespace std;

vector<long long> nextSmallerElements(long long arr[], int n){
    
    vector<long long> ans(n);
    stack<long long> st;
    st.push(-1);
        
    for(int i = n -1; i >= 0; i--){
        
        long long curr = arr[i];

        while(st.top() != -1 && (arr[st.top()] >= curr) ){
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
    
    
vector<long long> prevSmallerElements(long long arr[], int n){
    
    vector<long long> ans(n);
    stack<long long> st;
    st.push(-1);
        
    for(int i = 0; i < n; i++){
            
        long curr = arr[i];
            
        while(st.top() != -1 && arr[st.top()] >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
    
    //Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n){

    vector<long long> next(n);
    vector<long long> prev(n);
        
    next = nextSmallerElements(arr, n);
    prev = prevSmallerElements(arr, n);
        
    int area = INT_MIN;
       
    for(int i = 0; i < n ; i++){
        
        int length = arr[i];
        
        if(next[i] == -1){
            next[i] = n;
        }
            
        int breadth = next[i] - prev[i] - 1;
            
        int newArea = length*breadth;
            
        area = max(area, newArea);
    }
        
    return area;
}


int main(){

    long long arr[] = {6,2,5,4,5,1,6};
    long long maxArea = getMaxArea(arr,7);

    cout<<"Answer is : "<<maxArea<<endl;
}