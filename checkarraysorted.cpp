#include <bits/stdc++.h>
using namespace std;

bool arraySortedOrNot(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;

    if (arr[n - 2] > arr[n - 1])
        return false;

    return arraySortedOrNot(arr, n - 1);
}

int main()
{
    int arr[] = {20, 23, 23, 45, 78, 88};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (arraySortedOrNot(arr, n))
        cout << "Yes\n";
    else
        cout << "No\n";
}