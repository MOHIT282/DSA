#include <bits/stdc++.h>
using namespace std;

int getPartitionIndex(vector<int> &arr, int s, int e){

    int start = s;
    int end = e;

    int pivot = arr[s];
    int count = 0;

    for(int i = start +1; i<= end; i++){
        if(arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
     
    cout<<"pivot before swapping "<<arr[s]<<" "<<arr[pivotIndex]<<endl;
    if(pivotIndex != s)
        swap(arr[pivotIndex],arr[s]);
    cout<<"pivot After swapping "<<arr[s]<<" "<<arr[pivotIndex]<<endl<<endl;
    

    // now place the element smaller than actual pivot to left and the bigger to the right
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] <= pivot)
            i++;
        
        while(arr[j] > pivot)
            j--;
        
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}


void quickSort(vector<int> &arr,int s, int e){

    if(s >= e)
        return;

    int start = s;
    int end = e;
    
    int p = getPartitionIndex(arr,start,end);

    // sort krlo p ke left array or p ke right array ko

    quickSort(arr,start,p-1);
    
    quickSort(arr,p+1,end);
}


int main(){

    vector<int> v = {23,25,14,8,97,1,78,2,9,11,22,54,64,19,25,21};

    quickSort(v,0,v.size() -1);

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;

}