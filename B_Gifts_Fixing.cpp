// codeforces #661 div3
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rep(i, n) for (long long i = 0; i < n; i++)
#define loop(i, a, b) for (long long i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(vl a, vl b, int n)
{
    int temp, moves = 0, i = 0;
    auto minA = min_element(all(a));
    auto minB = min_element(all(b));
    while (i < n)
    {
        if (a[i] > *minA && b[i] > *minB)
        {
            temp = min(a[i] - *minA, b[i] - *minB);
            moves += temp;
            if (a[i] - temp > *minA)
            {
                moves += (a[i] - temp - *minA);
            }
            else if (b[i] - temp > *minB)
            {
                moves += (b[i] - temp - *minB);
            }
        }
        else if (a[i] > *minA)
        {
            moves += (a[i] - *minA);
        }
        else if (b[i] > *minB)
        {
            moves += (b[i] - *minB);
        }
        i++;
    }
    cout << moves << endl;
}

int32_t main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vl a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        solve(a, b, n);
    }

    return 0;
}