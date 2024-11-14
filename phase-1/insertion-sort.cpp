#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int size){

    for(int i = 1; i< size; i++){

        int temp = arr[i];
        int j = i - 1;

        while(j >= 0){

            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else
                break;
            
            j--;
        }
        arr[j+1] = temp;
    }
}

// void insertionSort2(int arr[], int size){

//     for(int i = 1; i< size; i++){

//         int temp = arr[i];
//         int curr = 0;
        
//         for(int j = 0; j < i; j++){

//             if( arr[j] > temp ){

//                 curr = arr[j];
//                 arr[j] = temp;
//             }
            
//             else break;
//         }
//     }
// }


int main(){

    // int arr[] = {7,9,1,5,14,6};
    // insertionSort(arr,6);

    // for(auto element : arr){
    //     cout<<element<<" ";
    // }

    int a = '3' - '0';
    cout<<( a + 8)<<endl;

}