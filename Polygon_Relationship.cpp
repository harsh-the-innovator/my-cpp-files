// codechef august cook off challenge
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int n)
{
    ll dp[n + 1];
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    loop(i, 6, n)
    {
        if (i % 2 == 0)
        {
            dp[i] = i + dp[i / 2];
        }
        else
        {
            dp[i] = i + dp[(i - 1) / 2];
        }
    }

    cout << dp[n] << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll x, y;
        rep(i, n)
        {
            cin >> x >> y;
        }
        solve(n);
    }

    return 0;
}