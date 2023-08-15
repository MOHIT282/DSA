#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Decimal to binary
    // int n;
    // cout << "Enter the no. : ";
    // cin >> n;
    // int ans = 0;
    // int i = 0;
    // while (n != 0)
    // {
    //     int bit = n & 1;
    //     // cout<< bit<<" x "<<pow(10,i)<<" + "<<ans<<endl;
    //     ans = (bit * pow(10, i)) + ans;
    //     n = n >> 1;
    //     i++;
    // }
    // cout << "Answer is : " << ans;


    // binary to decimal
    int n;
    cout<<"Enter the no. : ";
    cin>> n;
    int ans = 0;
    int i = 0;
    while(n != 0){
        int digit = n % 10;
        if(digit == 1){
            ans = (digit * pow(2,i)) + ans;
        }
        n = n / 10;
        i++;
    }
    cout<<"Answer is : "<<ans;
} 