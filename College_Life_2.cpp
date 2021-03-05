//codechef starters 2021 div3
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(vector<vi> &vv, int n, int q[])
{
    ll totalTime = 0;

    rep(i, n)
    {
        int ep = vv[i].size();
        rep(j, ep)
        {
            totalTime += (ll)vv[i][j];
        }
        totalTime -= (ll)(ep - 1) * (ll)q[i];
    }

    cout << totalTime << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        int q[s];
        rep(i, s)
        {
            cin >> q[i];
        }

        vector<vi> vv;
        int ei, l;

        rep(i, s)
        {
            cin >> ei;
            vi t;
            rep(j, ei)
            {
                cin >> l;
                t.push_back(l);
            }
            vv.push_back(t);
        }

        solve(vv, s, q);
    }

    return 0;
}