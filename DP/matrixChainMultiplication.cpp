// matrix chain multiplication recursive
#include <bits/stdc++.h>
using namespace std;
int MCM(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int resultMin = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (tempAns < resultMin)
        {
            resultMin = tempAns;
        }
    }
    return resultMin;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mimimum Number of operations = " << MCM(arr, 1, n - 1);
}