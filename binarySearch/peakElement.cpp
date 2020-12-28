#include <bits/stdc++.h>
using namespace std;

//Peak element is the element which is greater than equal to its neighbours
// and for first and last element we have to check only one sided neighbour
// solution is to use binary search
int findPeak(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        {
            return mid;
        }

        if (mid > 0 && arr[mid - 1] > arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1; // ans will never be -1 because their will always be peak element
}

int main()
{
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = findPeak(arr, n);
    cout << arr[index] << endl;
}