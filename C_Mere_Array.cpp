#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
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
        vl a(n);
        rep(i, n) cin >> a[i];
        vl v(n);
        rep(i, n)
        {
            v[i] = a[i];
        }

        sort(all(a));
        ll m = a[0];
        int flag = 0;
        rep(i, n)
        {
            if (v[i] != a[i])
            {
                if (a[i] % m != 0)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}