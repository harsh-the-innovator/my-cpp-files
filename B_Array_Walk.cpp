// codeforces educational round #92 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

ll dp[100002][6];

ll maxScore(vl &a, int n, int i, int k, int z)
{
    if (k == 0 or i < 0 or i >= n)
    {
        return 0;
    }
    if (dp[i][z] != -1)
        return dp[i][z];
    ll score = 0;
    if (i < n)
    {
        score = max(score, a[i] + maxScore(a, n, i + 1, k - 1, z));
    }
    if (i >= 0 && z > 0)
    {
        score = max(score, a[i] + maxScore(a, n, i - 1, k - 1, z - 1));
    }

    return dp[i][z] = score;
}

void solve(vl a, int n, int k, int z)
{
    ll score = maxScore(a, n, 1, k, z) + a[0];
    cout << score << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, k, z;
        cin >> n >> k >> z;
        vl a(n);
        rep(i, n) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        solve(a, n, k, z);
    }
    return 0;
}