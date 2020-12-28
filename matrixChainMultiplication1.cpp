// matrix chain multiplication recursive
#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];
int MCM(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int resultMin = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (tempAns < resultMin)
        {
            resultMin = tempAns;
        }
    }
    return t[i][j] = resultMin;
}
int main()
{
    int arr[] = {10, 30, 5, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(t, -1, sizeof(t));
    cout << "Mimimum Number of operations = " << MCM(arr, 1, n - 1);
}