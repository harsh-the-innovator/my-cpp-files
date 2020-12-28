// codeforces #367 div2 B
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

int binarySearch(vi &x, int start, int end, ll &key)
{
    if (start > end)
    {
        return 0;
    }

    int mid = (start + end) / 2;
    if (x[mid] <= key)
    {
        return mid;
    }
    else
    {
        return binarySearch(x, start, mid - 1, key);
    }
}

void solve(vi &x, vl &m, int &n, int &q)
{
    sort(all(x));
}

int main()
{
    int n, q;
    cin >> n;
    vi x(n);
    rep(i, n) cin >> x[i];
    cin >> q;
    vl m(q);
    rep(i, q) cin >> m[i];
    solve(x, m, n, q);
}