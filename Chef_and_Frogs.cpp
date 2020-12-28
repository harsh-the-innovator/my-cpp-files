#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
#define pli pair<long long, int>
#define pb push_back
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int n, p;
    ll k;
    cin >> n >> k >> p;
    ll x;
    vector<pli> vp;
    rep(i, n)
    {
        cin >> x;
        vp.pb({x, i});
    }

    sort(all(vp));

    int dp[n];
    memset(dp, -1, sizeof(dp));
    int idx = 0;
    dp[vp[0].ss] = idx;

    loop(i, 1, n - 1)
    {
        if ((vp[i].ff - vp[i - 1].ff) <= k)
        {
            dp[vp[i].ss] = idx;
        }
        else
        {
            dp[vp[i].ss] = ++idx;
        }
    }

    while (p--)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        if (dp[A] == dp[B])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}