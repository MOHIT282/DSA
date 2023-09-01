#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

vector<int> nextSmallerElements(int arr[], int n){
        
        cout<<"Entered nextSmallerElements function"<<endl;
        vector<int> ans(n);
        
        stack<int> st;
        st.push(-1);
        
        
        for(int i = n-1; i >= 0; i--){
            
            int curr = arr[i];
            
            while(st.top() != -1 and arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElements(int arr[], int n){
        
        cout<<"Entered prevSmallerElements function"<<endl;

        vector<int> ans(n);
        
        stack<int> st;
        st.push(-1);
        
        
        for(int i = 0; i < n; i++){
            
            int curr = arr[i];
            
            while(st.top() != -1 and arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestArea(int arr[], int n){

        cout<<"Largest Area function"<<endl;
        
        vector<int> next(n);
        vector<int> prev(n);
        
        int area = INT_MIN;
        
        next = nextSmallerElements(arr,n);
        prev = prevSmallerElements(arr,n);
        
        for(int i = 0; i < n; i++){
            
            if(next[i] == -1)
                next[i] = n;
            
            int l = arr[i];
            int b = next[i] - prev[i] -1;
            
            int newArea = l*b;
            
            area = max(area, newArea);
        }
        return area;
    }
  
    int maxArea(int M[4][4], int n, int m) {
        
        // find the largest area for first row
        
        cout<<"Entered in the main function"<<endl;

        int largeArea = largestArea(M[0], m);
        
        cout<<largeArea<<endl;

        for(int i = 1; i < n; i++){
            
            for(int j = 0; j < m; j++){
                
                 // add the upper row elements in the present row
                 
                if(M[i][j] != 0){
                    
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
            }
            
            largeArea = max(largeArea, largestArea(M[i], m) );
        }
        
        return largeArea;
    }

int main(){

    cout<<"matrix created "<<endl;
    
    int mat[4][4] = {

        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };


    int maxVal = maxArea(mat,4,4);
    cout<<"Max Area that can be formed is : "<<maxVal<<endl;
}