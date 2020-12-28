// codeforces #666 div2 B
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

void solve(vl &a, int n)
{
    sort(all(a));
    double sq = pow((double)a[n - 1], (1 / (n - 1)));
    cout << sq << endl;
}

int main()
{
    int n;
    cin >> n;
    vl a;
    rep(i, n) cin >> a[i];
    solve(a, n);

    return 0;
}