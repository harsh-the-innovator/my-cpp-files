// Given an array of positive numbers, find the maximum sum of a subsequence
// with the constraint that no 2 numbers in the sequence should be adjacent in the array.
// So 3 2 7 10 should return 13 (sum of 3 and 10)

// Algorithm:
// Loop for all elements in arr[] and maintain two sums incl and excl where incl = Max sum including the previous element and excl = Max sum excluding the previous element.

// Max sum excluding the current element will be max(incl, excl) and max sum including the current element will be excl + current element (Note that only excl is considered because elements cannot be adjacent).

// At the end of the loop return max of incl and excl.

//see gfg for reference

#include <bits/stdc++.h>
using namespace std;
int findMaxSum(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    for (int i = 1; i < n; i++)
    {
        /* current max excluding i */
        excl_new = max(incl, excl);

        /* current max including i */
        incl = excl + arr[i];
        excl = excl_new;
    }

    return max(incl, excl);
}
int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMaxSum(arr, n) << endl;
}