#include <bits/stdc++.h>
using namespace std;

int *reverseArray(int arr[], int i, int j)
{
    if (i < j)
    {
        swap(arr[i], arr[j]);
        reverseArray(arr, i + 1, j - 1);
    }

    return arr;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Before Reversing: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "After Reversing: " << endl;

    int *ptr = reverseArray(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr + i) << " ";
    }
}