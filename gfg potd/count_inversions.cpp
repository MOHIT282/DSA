#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    int count = 0;

    void merge(vector<int>& arr, int start, int end){

        int mid = start + (end - start)/2;

        vector<int> leftArray(arr.begin() + start, arr.begin()+mid+1); // create a left array
        vector<int> rightArray(arr.begin()+mid+1, arr.begin()+end + 1); // create a right array

        int i = 0, j = 0, k = start;

        while(i < leftArray.size() && j < rightArray.size()){

            if(leftArray[i] <= rightArray[j]){
                arr[k++] = leftArray[i++];
            }
            else{
                arr[k++] = rightArray[j++];
                count += leftArray.size() - i;
            }
        }

        while(i < leftArray.size()) arr[k++] = leftArray[i++];

        while(j < rightArray.size()) arr[k++] = rightArray[j++];

        return; // return the sorted array

    }
    void mergeSort(vector<int>& arr, int start, int end){

        if(start >= end) return; // if the start index is greater than or equal to the end index, then return
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, end); // merge the sorted arrays
    }

};

int main(){

    vector<int> arr = {2, 4, 1, 3, 5};
    Solution obj;
    obj.mergeSort(arr,0, arr.size()-1);

    for(int &i: arr) cout<<i<<" ";

    cout<<endl<<"count inversions : "<<obj.count;
    
}