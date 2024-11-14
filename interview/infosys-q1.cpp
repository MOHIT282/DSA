// given a boolean array of size n, find out the longest subarray having equal numbers of 0 and 1.
// 1 < n < 10^5

#include <bits/stdc++.h>
using namespace std;

int findMaxLength(int n, vector<int> &nums)
{

    unordered_map<int, int> occurence;

    occurence[0] = -1;
    int sum = 0;
    int maxLength = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i] == 1 ? 1 : -1;

        if (occurence.find(sum) != occurence.end())
        {

            maxLength = max(maxLength, i - occurence[sum]);
        }
        else
        {

            occurence[sum] = i;
        }
    }
    return maxLength;
}

int main()
{
    vector<int> A = {0, 1, 0, 0, 0, 0, 0, 0, 1};
    int ans = findMaxLength(8, A);
    cout << ans << endl;
    return 0;
}