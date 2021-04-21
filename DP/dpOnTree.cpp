// 1130. Minimum Cost Tree From Leaf Values
// see video on youtube for refernce
#include <bits/stdc++.h>
using namespace std;
pair<int, int> findMinCost(int arr[], int i, int j)
{
    if (i == j)
    {
        //first value id max value of leaf and second value is product of this node
        return {arr[i], 0};
    }

    int maxLeaf = INT_MIN;
    int minSum = INT_MAX;

    //partitioning at k
    for (int k = i; k < j; k++)
    {
        auto left = findMinCost(arr, i, k);
        auto right = findMinCost(arr, k + 1, j);
        maxLeaf = max(left.first, right.first);
        minSum = min(minSum, left.second + right.second + left.first * right.first);
    }

    return {maxLeaf, minSum};
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        auto ans = findMinCost(arr, 0, n - 1);
        cout << "ans = " << ans.second << endl;
    }
}