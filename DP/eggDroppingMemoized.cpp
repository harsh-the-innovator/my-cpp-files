#include <bits/stdc++.h>
using namespace std;

int solve(int e, int f, int **dp)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(solve(e - 1, k - 1, dp), solve(e, f - k, dp));
        ans = min(ans, temp);
    }
    return dp[e][f] = ans;
}

int eggDrop(int n, int k)
{
    //see bookmark pointer to pointers
    //allocating memory for rows
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[k + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -1;
        }
    }

    //for deallocating memory
    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    int ans = solve(n, k, dp);
    return ans;
}

int main()
{
    int e = 2, f = 10;
    cout << "Minimum number of attempts:" << eggDrop(e, f) << endl;
}