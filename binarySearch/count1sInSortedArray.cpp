// given binary array
// count 1's in sorted binary array
// using binary search
// solution is to find first occ of 1 using binary search
// and then we get the count of 1's by n-i
#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int low, int high, int x)
{ //finding first occurence using binary search
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
        {
            return firstOcc(arr, mid + 1, high, x);
        }
        else if (arr[mid] > x)
        {
            return firstOcc(arr, low, mid - 1, x);
        }
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                return firstOcc(arr, low, mid - 1, x);
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = firstOcc(arr, 0, n - 1, 1);
    if (i == -1)
        cout << "not found" << endl;
    else
        cout << "count = " << n - i << endl;
}