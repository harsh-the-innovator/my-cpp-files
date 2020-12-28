// search an element in rotated array
// using binary search
#include <bits/stdc++.h>
using namespace std;

int searchInRotated(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[low] <= arr[mid]) //left half sorted
        {
            if (x >= arr[low] && x < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else //right half sorted
        {
            if (x > arr[mid] && x <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {100, 200, 300, 400, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 40;
    int index = searchInRotated(arr, n, x);
    if (index != -1)
    {
        cout << index << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}