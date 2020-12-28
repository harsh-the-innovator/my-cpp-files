// codeforces global round 11, 2020
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

void solve(string s, int n, int k)
{
    int sum = 0;
    rep(i, n)
    {
        if (i == 0 && s[i] == 'W')
        {
            sum += 1;
        }
        else if (s[i] == 'W' && s[i - 1] == 'W')
        {
            sum += 2;
        }
        else if (s[i] == 'W')
        {
            sum += 1;
        }
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, n, k);
    }

    return 0;
}