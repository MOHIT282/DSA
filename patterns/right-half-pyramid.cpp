#include<bits/stdc++.h>
using namespace std;

void right_half_pyramid(int n){

    // *
    // * *
    // * * *
    // * * * *
    // * * * * *

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void left_half_pyramid(int n){

    for(int i = 1; i <= n; i++){

        for(int j = n - 1 ; j >= i; j--){
            cout<<" ";
        }

        for(int k = 1; k <= i; k++){
            cout<<"*";
        }
        cout<<endl;
    }
}


void full_pyramid(int n){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n - i; j++){
            cout<<" ";
        }

        for(int k = 0; k <= 2 * i - 1; k++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void inverted_left_half_pyramid(int n){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < i; j++)
            cout<<" ";
        
        for(int k = n - i; k > 0; k--)
            cout<<'*';
        
        cout<<endl;
    }
}

void full_inverted_pyramid(int n){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < i; j++)
            cout<<" ";
        
        for(int k = 0; k < 2 * (n - i) - 1; k++)
            cout<<"*";
        
        cout<<endl;

    }
}

void rhombus(int n){

    for(int i = 0; i< n; i++){

        for(int j = 0; j < i; j++)
            cout<<" ";
        
        for(int k = 0; k < n; k++)
            cout<<"*";

        cout<<endl;
    }
}

void diamond(int n){

    for(int i = 0; i < n - 1; i++){

        for(int j = 0; j < n - i - 1; j++)
            cout<<" ";
        
        for(int k = 0; k < (2 * i) + 1; k++)
            cout<<"*";

        cout<<endl;
    }

    for(int i = 0; i < n ; i++){

        for(int j = 0; j < i; j++)
            cout<<" ";

        for(int k = 0; k < 2 * (n - i) - 1; k++)
            cout<<"*";

        cout<<endl;
    }
}

void hourGlass(int n){

    for(int i = 0; i < n - 1 ; i++){

        for(int j = 0; j < i; j++)
            cout<<" ";

        for(int k = 0; k < 2 * (n - i) - 1; k++)
            cout<<"*";

        cout<<endl;
    }

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n - i - 1; j++)
            cout<<" ";
        
        for(int k = 0; k < (2 * i) + 1; k++)
            cout<<"*";

        cout<<endl;
    }
}

void hollowSquare(int n){

    for(int i = 0; i < n; i++)
        cout<<"* ";
    cout<<endl;

    for(int i = 0; i < n - 2; i++){

        cout<<"* ";

        for(int j = 0; j < n - 2; j++)
            cout<<"  ";
        
        cout<<"* ";

        cout<<endl;
    }

    for(int i = 0; i < n; i++)
        cout<<"* ";
}

// void hollow_full_pyramid(int n){

//     for(int i = 0; i < n; i++){

//         for(int j = 0; j < n - i - 1; j++)
//             cout<<" ";

//         for(int k = 0; k < 2*i + 1; k++){

//             if(k == 0 || k = 2*i ){}
//         }
//     }
// }

void floydsTriangle(int n){

    int count = 1;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= i; j++){
            
            cout<<count++<<" ";
        }
        cout<<endl;
    }
}

void pascalsTriangle(int n){

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n - i; j++)
            cout<<" ";

        int count = 1;
        for(int k = 1; k <= i; k++){

            cout<<count<<" ";
            count = count * (i - k)/k;
        }
        cout<<endl;
    }
}


int main(){

    // right_half_pyramid(6);
    // left_half_pyramid(6);
    // full_pyramid(5);
    // inverted_left_half_pyramid(6);
    // full_inverted_pyramid(7);
    // rhombus(7);
    // diamond(5);
    // hourGlass(5);
    // hollowSquare(10);
    // floydsTriangle(6);
    pascalsTriangle(5);
}