#include<bits/stdc++.h>
using namespace std;

int firstOccur(int arr[], int n, int x){
	    
    int beg = 0;
    int end = n-1;
    int ans = -1;
    int mid;
    while(beg <= end){
        
        mid = beg + (end - beg)/2;
        
        if(arr[mid] == x){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid] < x){
            beg = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return ans;
}
	
int lastOccur(int arr[], int n, int x){
	    
	int beg = 0;
	int end = n-1;
	int ans = -1;
	int mid;
	while(beg <= end){
	        
	    mid = beg + (end - beg)/2;
	        
	    if(arr[mid] == x){
	        ans = mid;
	        beg = mid + 1;
	    }
	    else if(arr[mid] < x){
	        beg = mid + 1;
	    }
	    else{
	        end = mid -1;
	    }
	}
	return ans;
}



int main(){

    int arr[] = {1,1,1,2,2,2,2,2,2,3,3,4,5};

    int first = firstOccur(arr,13,2);
    int last = lastOccur(arr,13,2);

    cout<<"The first occurence is : "<<first<<endl<<"The last Occurence is : "<<last<<endl;

}