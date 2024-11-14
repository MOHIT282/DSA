#include<bits/stdc++.h>
using namespace std;

vector<int> findPrimeFactors(int num){

    int n = num/4;
    vector<int> primes;

    for(int i = 2; i < n; i++){
        
        if(num % i == 0){
            bool notPrime = false;

            for(auto &j: primes){
                if( i % j == 0){
                    notPrime = true;
                    break;
                }
            }
            if(!notPrime) primes.push_back(i);
        }
    }
    return primes;
}

int main(){

    int num = 81;
    cout<<"Prime factors of "<<num<<" are -->";
    vector<int> ans = findPrimeFactors(num);
    for(auto &i : ans){
        cout<<i<<" "; 
    }
}