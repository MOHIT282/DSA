#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // int n;
    // cout << "Ente the no. : ";
    // cin >> n;
    
    // for(int i = 0; i <= 30; i++){

    //     if( n == pow(2,i)){
    //         cout<<"It is in power of 2";
    //         return 0;
    //     }
    // }
    // cout<<"It is not in power of 2";

    // Another method

    int m;
    cout<<"Enter the no. : ";
    cin>>m;

    if( ceil(log2(m)) == floor(log2(m))){
        cout<<"The number can be represented as a power of 2";
    }
    else{
        cout<<"The number is not representable as power of 2";
    }
}