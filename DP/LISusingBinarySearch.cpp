// LIS using binary search and auxillary search //Time = O(nlogn)
#include <bits/stdc++.h>
using namespace std;
int ceilIndex(vector<int> &tail, int l, int r, int x)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (x <= tail[m])
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return r;
}
int lis(int arr[], int n)
{
    vector<int> tail;
    int len = 1;
    tail.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail.back())
        {
            tail.push_back(arr[i]);
            len++;
        }
        else
        {
            int c = ceilIndex(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }

    return len;
}
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d", lis(arr, n));
}