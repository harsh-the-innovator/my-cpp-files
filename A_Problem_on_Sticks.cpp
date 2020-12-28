// codechef september long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        set<ll> s;
        rep(i, n)
        {
            cin >> a[i];
            if (a[i] != 0)
                s.insert(a[i]);
        }
        cout << s.size() << endl;
    }

    return 0;
}