#include <iostream>
using namespace std;

int main()
{
    //  1 2 3 4 5 .. n
    //  1 2 3 4 5 .. n
    //  1 2 3 4 5 .. n
    //  1 2 3 4 5 .. n

    // int n;
    // cin >> n;
    // int i = 1;
    // while(i <= n){
    //     int j = 1;
    //     while(j <= n){
    //         cout << n - j + 16 ;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    // printing the star pyramid here...
    // int i = 1 , n;
    // cin >> n;
    // while(i <= n){
    //     int j = 1;
    //     while(j <= i){
    //         cout << "* ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    // int i = 1, n;
    // cin >> n;
    // while (i <= n)
    // {
    //     int value = i;
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << value << " ";
    //         value --;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }

    int n;
    cin >> n;
    int i = 1;
    while (i <= n) 
    {
        // upper square

        // left numnbers
        int lt = 1;
        while(lt <= (n - i) + 1){
            cout<< lt;
            lt++;
        }

        // left stars
        int ls = 1;
        while (ls <= i -1){
            cout<< "*";
            ls++;
        }

        // right square

        // right stars
        int rs = 1;
        while(rs <= i - 1){
            cout<<"*";
            rs++;
        }

        // right triangle
        int rt = n - i + 1;
        while( rt){
            cout<<rt;
            rt--;
        }


        i++;
        cout<<endl;
    }
}