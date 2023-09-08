#include<bits/stdc++.h>
using namespace std;

int max_min(int *arr,int n, int k){

    deque<int> maxi(k);
    deque<int> mini(k);

    for(int i = 0; i < k; i++){

        while(!maxi.empty() && arr[maxi.front()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.front()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);       
    }
    int sum = 0;

    sum = arr[maxi.front()] + arr[mini.front()];

    for(int i = k; i < n; i++){

        

    }
}


int main(){

}