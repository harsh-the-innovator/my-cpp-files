// check if there is a triplet with given sum in a sorted arrat
// if array is unsorted then first sort it then use this approach
// two pointer approach

#include <bits/stdc++.h>
using namespace std;
bool isPair(int arr[], int left, int right, int x)
{
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == x)
        {
            return true;
        }
        else if (sum > x)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return false;
}

bool checkTriplet(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (isPair(arr, i + 1, n - 1, x - arr[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 32;
    cout << checkTriplet(arr, n, x);
}