//codechef march long challenge 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    fast int t;
    cin >> t;
    while (t--)
    {
        ll c;
        cin >> c;
        ll n = (ll)log2(c) + 1;
        n = (ll)pow(2, n);
        ll ans;
        if (n == c)
        {
            ans = (ll)(n - 1) * (ll)(2 * n - 1);
        }
        else
        {
            n = n / 2;
            ans = (ll)(n - 1) * (ll)(3 * n - c - 1);
        }

        cout << ans << endl;
    }

    return 0;
}