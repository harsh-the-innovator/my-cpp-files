// longest increasing subsequence //Time = O(n^2)
#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n)
{
    if (n == 1)
        return 1;

    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    //finding max of all lis
    return *max_element(lis, lis + n);
}
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d", lis(arr, n));
}