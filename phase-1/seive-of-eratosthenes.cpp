// for a giprimesen number n, find the total no. of prime numbers that are strictly less than or equal to n
// There also exist a advanced version of this techniques known as segmented sieve.. learn about that on Coding Ninja 
#include <bits/stdc++.h>
using namespace std;

int findPrime(int n){

    vector<bool> primes(n+1,true); // initializing a primesector primes of size and all the primesalues are true;
    int count = 0;

    primes[0] = primes[1] = false;

    for(int i = 2; i < n; i++){

        if(primes[i] == true){
            count++;

            for(int j = 2*i; j < n; j+= i){
                primes[j] = false;
            }
        }
    }
    return count;
}

int main(){

    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<findPrime(n);

}