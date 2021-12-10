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

void solve(ll n, int d)
{
    string str = to_string(n);
    int len = str.length();
    ll resultSum = 0;
    int p = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == d + '0')
        {
            if (i == n - 1)
            {
                int num = d + 1;
                if (num == 10)
                {
                }
            }
            else
            {
                int prevNum = stoi(str.substr(i + 1, len));
            }
        }
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n;
        int d;
        cin >> n >> d;
        solve(n, d);
        cout << endl;
    }

    return 0;
}