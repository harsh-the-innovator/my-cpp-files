// count number of occurences in sorted array
// using binary search

// step 1 = find first occurence of element
// step 2  = find last occurence of element
// step 2 = take difference

#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &arr, int low, int high, int x)
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

int lastOcc(vector<int> &arr, int n, int low, int high, int x)
{ //finding last occurence using binary search
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
        {
            return lastOcc(arr, n, mid + 1, high, x);
        }
        else if (arr[mid] > x)
        {
            return lastOcc(arr, n, low, mid - 1, x);
        }
        else
        {
            if (mid == n - 1 || arr[mid] != arr[mid + 1])
            {
                return mid;
            }
            else
            {
                return lastOcc(arr, n, mid + 1, high, x);
            }
        }
    }
    return -1;
}

void solve(vector<int> &arr, int n, int x)
{
    int i = firstOcc(arr, 0, n - 1, x);
    if (i == -1)
    {
        cout << "Not found" << endl;
        return;
    }
    int j = lastOcc(arr, n, 0, n - 1, x);
    cout << "count = " << j - i + 1 << endl;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> arr;
    int el;
    for (int i = 0; i < n; i++)
    {
        cin >> el;
        arr.push_back(el);
    }
    cin >> x;
    solve(arr, n, x);
}