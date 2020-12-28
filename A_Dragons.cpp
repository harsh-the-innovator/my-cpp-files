// codeforces #142 div2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define pi pair<long long, long long>
#define rep(i, n) for (long long i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

bool comp(pi p1, pi p2)
{
    if (p1.first <= p2.first)
        return true;
    return false;
}

int32_t main()
{
    fast int s, n;
    cin >> s >> n;
    vector<pi> a(n);
    rep(i, n)
    {
        cin >> a[i].ff >> a[i].ss;
    }

    sort(all(a), comp);

    int i = 0;
    bool flag = 0;
    while (i < n)
    {
        if (s > a[i].first)
        {
            s += a[i].second;
            i++;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}