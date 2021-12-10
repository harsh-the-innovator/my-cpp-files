#include <bits/stdc++.h>
using namespace std;

// Given an array of positive numbers and a positive number ‘S’,
// find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’.
// Return 0, if no such subarray exists.

int smallestSubarraywithGivenSum(int arr[], int n, int S)
{
    int cur_sum = 0;
    int minLength = INT_MAX;
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        cur_sum += arr[end];

        while (cur_sum >= S)
        {
            minLength = min(minLength, end - start + 1);
            cur_sum -= arr[start];
            start++;
        }
    }

    if (minLength == INT_MAX)
        return 0;

    return minLength;
}

int main()
{
    int arr[] = {2, 1, 5, 2, 3, 2};
    int sum = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << smallestSubarraywithGivenSum(arr, n, sum);

    return 0;
}