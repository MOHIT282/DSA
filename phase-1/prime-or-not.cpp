#include <iostream>
using namespace std;

int main(){
    int n;
    bool isPrime = true ;
    cout<<"Enter the number you want to check it is prime or not : ";
    cin>>n;
    for(int i = 2; i <= n-1; i++){
        if(n % i == 0){
            isPrime = false;
            break;
        }
    }
    if (isPrime){
        cout<<n<<" is a prime number";
    }
    else{
        cout<<n<<" is not a prime number";
    }

}