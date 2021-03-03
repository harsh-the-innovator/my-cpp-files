#include <bits/stdc++.h>
using namespace std;
int eggDrop(int e, int f)
{
    int dp[e + 1][f + 1];

    //when f = 0 or f = 1
    for (int i = 1; i <= e; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    //for 1 egg
    for (int j = 1; j <= f; j++)
    {
        dp[1][j] = j;
    }

    int res;

    for (int i = 2; i <= e; i++)
    {
        for (int j = 2; j <= f; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j])
                {
                    dp[i][j] = res;
                }
            }
        }
    }

    return dp[e][f];
}

int main()
{
    int e = 2, f = 10;
    cout << "Minimum number of attempts:" << eggDrop(e, f) << endl;
}