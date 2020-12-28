// codeforces Round #655 div2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define I INT_MAX
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vector <int> vi
#define pb push_back
#define pair <int, int> pi
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
void solve(int n)
{
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << endl;
    }
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << n / i << " " << (n - n / i) << endl;
                return;
            }
        }
        cout << "1 " << n - 1 << endl;
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}