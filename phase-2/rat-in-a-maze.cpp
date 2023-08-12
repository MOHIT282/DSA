#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<int>> &arr, vector<vector<int>>& visited, int x, int y,int n){

    // cout<<"Value of x and y is : "<<x<<" "<<y<<endl;

    if( ((x < n && y < n ) && visited[x][y] == 0 && arr[x][y] == 1) &&  (x >= 0 && y >= 0)){
        // cout<<"returning true"<<endl;
        return true;
    }
    else{
        // cout<<"returning false"<<endl;
        return false;
    }
}


    void solve(vector<vector<int>> &arr, vector<vector<int>> visited, int n, int x, int y, string path, vector<string>& ans){

        // cout<<"new call initiated"<<endl;
        
        if(x == n -1 && y == n -1){
            ans.push_back(path);
            return;
        }

        // cout<<"value of path is "<<path<<endl;

        // mark the location as visited in the visited 2d vector whereever you are in the maze
        visited[x][y] = 1;

        //mouse can go in 4 directions from here i.e. UP DOWN LEFT RIGHT 
        // for up x => x -1 , y => y
        // for down x => x +1 , y => y
        // for left x => x, y => y -1
        // for right x => x, y => y +1

        //for down
        int new_x = x + 1;
        int new_y = y;
        // cout<<"checking for down direction"<<endl;
        if(isPossible(arr,visited,new_x,new_y,n)){
            // cout<<"true received for down direction"<<endl;
            path.push_back('D');
            solve(arr, visited, n, new_x, new_y,path,ans);
            //backtracking
            path.pop_back();
        }

        //for left
        new_x = x;
        new_y = y - 1;
        // cout<<"checking for left direction"<<endl;
        if(isPossible(arr,visited,new_x,new_y,n)){
            path.push_back('L');
            solve(arr, visited, n, new_x, new_y,path,ans);
            //backtracking
            path.pop_back();
        }

        //for right
        new_x = x;
        new_y = y + 1;
        // cout<<"checking for right direction"<<endl;
        if(isPossible(arr,visited,new_x,new_y,n)){
            // cout<<"True recieved for right direction"<<endl;
            path.push_back('R');
            solve(arr, visited, n, new_x, new_y,path,ans);
            //backtracking
            path.pop_back();
        }
        
        //for up
        new_x = x - 1;
        new_y = y;
        // cout<<"Checking for up direction"<<endl;
        if(isPossible(arr,visited,new_x,new_y,n)){
            path.push_back('U');
            solve(arr, visited, n, new_x, new_y,path,ans);
            //backtracking
            path.pop_back();
        }
        
        visited[x][y] = 0;

    }

    
    
    vector<string> findPath(vector<vector<int>> &arr, int n) {

        vector<string> ans;

        if(arr[0][0] == 0)
            return ans;
    
        vector<vector<int>> visited(n, vector<int>(n,0));
        string path = "";
        int src_x = 0;
        int src_y = 0;
    
        solve(arr, visited, n, src_x, src_y, path, ans);
    
        return ans;
    }



int main()
{
    vector<vector<int>> v = 
    {
        {1,0},
        {1,1}
    };
    vector<string> ans = findPath(v,2);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;


}