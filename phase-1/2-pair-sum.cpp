#include <bits/stdc++.h>
using namespace std;


vector< vector<int> > twoPairSum( vector<int> &arr, int sum){

    vector< vector <int> > ans;

    for(int i = 0; i < arr.size(); i++){
        
        for(int j = i+1; j < arr.size(); j++){

            vector<int> temp;

            if( arr[i]+ arr[j] == sum){
                temp.push_back( min(arr[i],arr[j]) );
                temp.push_back( max(arr[i],arr[j]) );
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}


int main(){

    vector<int> vect{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector< vector<int> > vect2 =   twoPairSum(vect,12);

    for(int i = 0; i< vect2.size(); i++){
        
        for(int j = 0; j < vect2[i].size(); j++){
            cout<<vect2[i][j]<<" ";
        }
        cout<<endl;
    }

}