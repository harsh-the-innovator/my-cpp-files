// given an array of integers and a number k find the max sum of k consecutive
// numbers
// window sliding technique

#include <bits/stdc++.h>
using namespace std;
void maxSumK(int arr[], int n, int k)
{
    int cur_sum = 0;
    for (int i = 0; i < k; i++)
    {
        cur_sum += arr[i];
    }

    int res = cur_sum;
    for (int i = k; i < n; i++)
    {
        cur_sum += arr[i] - arr[i - k];
        res = max(res, cur_sum);
    }

    cout << res << endl;
}
int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSumK(arr, n, k);
}