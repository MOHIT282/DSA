#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    vector<int> arr = {112, 142, 115, 159, 22, 63, 865, 190, 5732, 958};

    insertion_sort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}