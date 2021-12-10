// CODECHEF STARTERS 15
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
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

void solve(int n, int d)
{
    int num = n, pos = 0, ans = 0;
    while (num > 0)
    {
        int digit = num % 10;
        num = num / 10;
        pos++;
        if (digit == d)
        {
            num = num * pow(10, pos) + (digit + 1) * pow(10, pos - 1);
            ans = num - n;
            pos = 0;
        }
    }

    cout << ans << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        solve(n, d);
    }

    return 0;
}