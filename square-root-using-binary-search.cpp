// find the root of a number 
// if we apply linear search which is brute force... the time complexity will be root(n) where n is length of array
// we will apply binary search as the time complexity will be of O(logn0)

#include <iostream>

using namespace std;


long long int findSquareRoot(int num){

    int beg = 0, end = num;
    long long int ans = -1, mid;
    while(beg <= end){

        mid = beg + (end - beg)/2;

        if(mid*mid == num){
            return mid;
        }
        else if( mid*mid > num){
            end = mid - 1;
        }
        else if(mid*mid < num){
            ans = mid;
            beg = mid + 1;
        }
    }
    return ans;
}

double getPrecision(int num, int precision, int sqrRoot){

    double ans = sqrRoot;
    double factor = 1 ;
    for(int i = 0; i< precision; i++){
        factor = factor/10;

        for(double j = ans; j*j < num; j =j+ factor){
            ans = j;
        }
    }
    return ans;
}



int main(){

    int n;
    cout<<"Enter the number : ";
    cin>>n;
    double root = getPrecision(n,3,findSquareRoot(n));
    cout<<"The Square root of "<<n<<" is : "<<root<<endl;
}