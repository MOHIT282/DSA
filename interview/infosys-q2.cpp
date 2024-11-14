#include <bits/stdc++.h>
using namespace std;

int FindSubArrays(vector<int> &arr, int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; ++i)
    {
        int j = i;
        while (j <= end && (j == i || arr[j] >= arr[j - 1]))
        {
            count = (count + 1) % 1000000007;
            j++;
        }
    }
    return count;
}

// Function to get the count of non-decreasing subarrays for each query
int getCount(int N, vector<int> A, int Q, int T, vector<vector<int>> &P)
{
    int ans = 0;

    for (int i = 0; i < Q; ++i)
    {
        if (P[i][2] != 0)
        {
            // Update the array based on the query
            for (int j = P[i][0]; j <= P[i][1]; ++j)
            {
                if (A[j] != 0)
                    A[j] = P[i][2];
            }
        }
        else
        {
            // Calculate the number of non-decreasing subarrays in the range
            ans = (ans + FindSubArrays(A, P[i][0], P[i][1])) % 1000000007;
        }
    }

    return ans % 1000000007;
}

int main()
{

    vector<int> A = {5, 5, 4, 3, 2, 1, 5, 3};

    vector<vector<int>> P = {
        {2, 5, 0},
        {1, 3, 0},
        {2, 3, 0},
        {3, 5, 0},
        {1, 5, 0}};

    int ans = getCount(8, A, 5, 3, P);

    cout << ans;
}