#include <bits/stdc++.h>
using namespace std;

// bool isPossible(int n, vector<vector<int>> arr, int B, int mid)
// {
//     int tCount = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 1; j <= arr[i][0]; j++)
//         {
//             if (arr[i][j] <= mid)
//             {
//                 tCount += arr[i][j];
//             }
//         }
//         if (tCount > B)
//             return false;
//     }
//     return true;
// }


// int findMaxX(int n, vector<vector<int>> &arr, int B)
// {
//     int s = 0, e = 0, sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum = 0;
//         for (int j = 1; j <= arr[i][0]; j++)
//         {
//             sum += arr[i][j];
//         }
//         e = max(e, sum);
//     }
//     int mid = s + (e - s) / 2, ans = -1;
//     while (s <= e)
//     {
//         if (isPossible(n, arr, B, mid))
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else
//             e = mid - 1;
//         mid = s + (e - s) / 2;
//     }
//     return ans;
// }

void reverseString(vector<char>& s) {
        int n = s.size();
        // cout<<n<<endl;
        for(int i = 0; i< n/2; i++){
            cout<<s[i]<<" "<<s[n-1-i]<<endl;
            swap(s[i],s[n-1-i]);
        }
    }

int main(){
    
    // vector<char> vect = {'h','e','l','l','o'};
    // reverseString(vect);
    // cout<<vect[0]<<endl;
    // for(int i = 0; i< vect.size(); i++){
    //     cout<<vect[i]<<" ";
    // }

    string str = "daabcbaabcbc";
    string sbstr = "abc";
    

    while(true){

        if(str.find(sbstr) ==-1){
            break;
        }
        else{
            int pos = str.find(sbstr);
            str.erase(pos,sbstr.length());
        }
    }
    cout<<str;

}