#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat){

    vector<int> temp;
    for(int i = 0; i < N; i++){

        for(int j = 0; j < N; j++){

            temp.push_back(Mat[i][j]);

        }
    }

    sort(temp.begin(),temp.end());

    int count = 0;

    for(int i = 0; i < N; i++){

        for(int j = 0; j < N; j++){

            Mat[i][j] = temp[count];
            count++;
        }
    }
    return Mat;
}

int main(){

    vector<vector<int>> Mat =
    {{10,20,30,40},
    {15,25,35,45}, 
    {27,29,37,48},
    {32,33,39,50}};

    vector<vector<int>> ans = sortedMatrix(4,Mat);

     for(int i = 0; i < 4; i++){

        for(int j = 0; j < 4; j++){

            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}