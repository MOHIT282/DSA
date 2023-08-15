#include <bits/stdc++.h>
using namespace std;

int main(){

    // both the array are sorted as given in the question
    int arr[5] = {-5,1,5,23,53};
    int brr[5] = {0,2,5,23,49};

    int sizeA = sizeof(arr)/sizeof(int);
    int sizeB = sizeof(brr)/sizeof(int);

    vector<int> ans;
    for(int i = 0; i < sizeA; i++){
        
        for(int j = 0; j < sizeB; j++){
            if(arr[i] < brr[j])
                break;
                
            if(arr[i] == brr[j]){
                ans.push_back(arr[i]);
                brr[j] = INT_MIN;
                break;
            }
        }
    }
    for(int i =0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i =0; i < sizeB; i++){
        cout<<brr[i]<<" ";
    }

    // two pointer approach

    int i = 0, j = 0;
    vector<int> ans2;
    while(i < sizeA && j < sizeB){

        if(arr[i] == brr[j]){
            ans2.push_back(arr[i]);
            i++;
            j++;
        }

        else if (arr[i] > brr[j]){
            j++;
        }
        else{
            i++;
        }
    }
    for(int i =0; i < ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }

    // time complexity has been decreased from O(n^2) to O(n)

}