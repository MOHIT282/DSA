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
            cout<<'A' + i<<" ";
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

void diamond(int rows){

    for(int i =0; i < rows - 1; i++){
        
        for(int j = 0; j < rows - i - 1; j++){
            cout<<"  ";
        }
        
        for(int k = 0; k < 2 * i + 1; k++){
            cout<<k+1<<" ";
        }
        cout<<endl;
    }
    
    for(int i = 0; i < rows; i++){
        
        for(int j = 0; j < i; j++)
            cout<<"  ";
            
        for(int k = 0; k < 2 * (rows - i) - 1; k++)
            cout<<k+1<<" ";
        
        cout<<endl;
    }
}

void hollow_diamond(int rows){

    for(int i = 0; i < rows - 1; i++){

        for(int j = 0; j < rows - i - 1; j++)
            cout<<"  ";

        for(int k = 0; k < 2 * i + 1; k++){

            if(k == 0 || k == 2 * i|| i == rows - 1)
                cout<<"* ";
            
            else{
                cout<<"  ";
            }
        }
        cout<<endl;

    }

    for(int i = 0; i < rows; i++){

        for(int j = 0; j < i; j++)
            cout<<"  ";

        for(int k = 0; k < 2 * (rows - i) - 1; k++){

            if(k == 0 || k == 2*(rows - i) - 2)
                cout<<"* ";
            
            else
                cout<<"  ";
        }
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

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if((i > 0 && i < n - 1) && (j > 0 && j < n - 1))
                cout<<"  ";
            else
                cout<<j<<" ";
        }
        cout<<endl;
    }
}

void hollow_full_pyramid(int n){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n - i - 1; j++)
            cout<<"  ";
        
        for(int k = 0; k < 2 * i + 1; k++){

            if( k == 0 || k == 2 * i || i == n - 1 )
                cout<<"* ";
            else
                cout<<"  ";
        }
        cout<<endl;
    }
}

void hollow_inverted_Pyramid(int n){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < i; j++)
            cout<<"  ";

        for(int k = 0; k < 2 * (n - i) - 1; k++){

            if( k == 0|| k == 2 * (n - i) - 2 || i == 0)
                cout<<"* ";
            else
                cout<<"  ";
        }
        cout<<endl;
    }
}


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

void pyramid(int rows){

    for(int i = 0; i < rows; i++){

        for(int j = 0; j <= i; j++){
            cout<<i+1;
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
    // pascalsTriangle(5);
    // hollow_full_pyramid(5);
    // hollow_inverted_Pyramid(5);

    pyramid(5);
}