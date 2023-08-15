#include <iostream>
using namespace std;

// input - 5 -> 101
// output - 2 -> 010

int main(){
    int n;
    cout<<"Enter the no. : ";
    cin>> n;
    int m = n;
    int mask = 0;

    // edge case
    if (m == 0){
        cout<< 1;
        return 0;
    }
    while(m != 0){
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & mask;
    cout<<ans<<endl;
}