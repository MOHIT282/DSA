#include <iostream>
#include <math.h>

using namespace std;

void reverseArray(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}

int main()
{
    int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    reverseArray(arr,11);
    return 0;
}