#include <bits/stdc++.h>
using namespace std;


bool isAnagram(string a, string b){

    
    int index1 = 'm' - 'a';    
    cout<<index1<<endl;
        
    }

int multipleLength(vector<int> &a, int n) {
    
    long long int product = 0;

    for(int i = 0; i < n; i++){
        product = product * a[i];
        cout<<"value of product is "<<a[i]<<endl;
    }
    cout<<"value of product is : "<<product<<endl;
    vector<int> ans;

    while(product != 0){

        int digit = product & 1;
        ans.push_back(digit);

        product = product / 2;
    }
    return ans.size();
}


int main(){

    string a = "abcde";
    string b = "ecdba";

    int *ptr = 0;
    cout<<sizeof(ptr)<<endl;

    isAnagram(a,b);

    vector<int> v = {1,2,3,4,5};

    int ans = multipleLength(v,5);

    cout<<ans;

}