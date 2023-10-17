#include <bits/stdc++.h>
using namespace std;

class maxheap{

    public:
    int *arr = new int[10000];
    int size= 0;

    void insert(int val){

        int index = size;
        arr[index] = val;
        size += 1;

        while(index > 0){
            
            int parent = (index - 1)/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deleteFromHeap(){

        if(size == 0){
            cout<<"Nothing to delete :(";
            return;
        }
        // replace the value of last node to the top root node
        arr[0] = arr[size - 1];
        size--;

        int index = 0;
        while(index < size){

            int leftIndex = 2*index + 1;
            int rightIndex = 2*index + 2;

            int biggerChildIndex = (arr[leftIndex] > arr[rightIndex] ) ? leftIndex : rightIndex;

            if(arr[index] < arr[biggerChildIndex]){
                swap(arr[index], arr[biggerChildIndex]);
                index = biggerChildIndex;
            }
            else{
                return;
            }
        }
    }

    void print(){

        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};


void heapify(int arr[], int n, int i){

    int largest = i; 
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){

    // maxheap obj;

    // obj.insert(54);
    // obj.insert(43);
    // obj.insert(50);
    // obj.insert(69);
    // obj.insert(20);
    // obj.insert(100);
    // obj.insert(78);
    // obj.insert(112);

    // obj.print();

    // obj.deleteFromHeap();
    // obj.print();
    // obj.deleteFromHeap();
    // obj.print();
    
    int arr[10] = {1, 23, 4,3,8, 10, 20,33, 78};
    int n =  10;
    for(int i = n/2; i>= 0; i--){
        heapify(arr, n, i);
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}