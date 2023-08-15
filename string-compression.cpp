#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars){

    int i = 0;
    int n = chars.size();
    int index = 0;
    while(i < n){

        int j = i+1;
        while(j < n && chars[i] == chars[j]){
            j++;            
        }
        // ya to array khatam ho gya ya naya character aa gya hoga

        chars[index++] = chars[i];

        // to find out how many same characters occured continously
        int count = j - i;

        string countIndex = to_string(count);

        for(auto ch : countIndex){
            chars[index++] = ch;
        }

        // take the i to j so that the loops start again for next character
        i = j;
    }
    return index;
}


int main(){

    vector<char> v = {'a','a','b','b','c','c','c'};
    int ans = compress(v);
    cout<<ans;
}