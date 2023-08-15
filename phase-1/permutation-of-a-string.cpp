#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int arr1[], int arr2[]){

    for(int i = 0; i < 26; i++){

        if(arr1[i] != arr2[i])
            return false;
    }
    return true;

}

bool checkInclusion(string s1, string s2){

    // creating a count array of s1
    int count1[26] = {0};

    for(int i = 0; i < s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }


    // creation of a window to compare the elements of s1 with s2
    // first traverse the s2 in the window before comparing

    int i = 0, windowSize = s1.length();
    int count2[26] = {0};

    while(i < windowSize){

        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    
    // check if the permutations matches 

    if(checkEqual(count1, count2)){
        return 1;
    }

    while(i < s2.length()){
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;

        if(checkEqual(count1, count2)){
            return 1;
        }
        i++;
    }
    return 0;
}

int main(){

}