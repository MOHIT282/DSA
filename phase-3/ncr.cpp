#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007


int nCr(int n, int r){
        
        cout<<"n : "<<n<<endl<<"r : "<<r<<endl;

        if(n == r || r == 0) return 1;
        
        if(n < r) return 0;
        
        long long int n_fact = n;
        long long int n_r_fact = 1;

        
        for(int i = 1; i <= n - r; i++){                
            n_r_fact = n_r_fact * i % MOD;
        }
        
        while(n - 1 > r){
            n_fact = n_fact * (--n);
        }
        cout<<"N factorial : "<<n_fact<<endl;
        cout<<"N - R factorial : "<<n_r_fact<<endl;

        return  n_fact / ( n_r_fact % MOD) ;
        
    }


int main(){

    cout<<nCr(45,34)<<endl;
}