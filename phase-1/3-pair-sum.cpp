#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > threePairSum(vector<int> &arr, int target ){

    vector< vector<int> > ans;

    for(int i = 0; i< arr.size(); i++){
        // cout<<"Inside the first for loop"<<endl;
        
        for(int j = i + 1; j< arr.size(); j++){
            // cout<<"Inside the second for loop"<<endl;    

            for(int k = j + 1; k< arr.size(); k++){
                // cout<<"Inside the third for loop"<<endl;    

                vector<int> temp;

                if( (arr[i] + arr[j] + arr[k]) == 0){
                    cout<<"<-------We are inside the if statement---------->"<<endl;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                // cout<<endl;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}



int main(){

    vector<int> vect{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector< vector<int> > vect2 =   threePairSum(vect,12);

    for(int i = 0; i< vect2.size(); i++){
        
        for(int j = 0; j < vect2[i].size(); j++){
            cout<<vect2[i][j]<<" ";
        }
        cout<<endl;
    }
}