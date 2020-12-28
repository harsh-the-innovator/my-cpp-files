// codeforces round #633 div2 B
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define vint vector<int>
#define vll vector<long long>
#define pint pair<int, int>
#define pll pair<long long, long long>
#define pi 3.1415926535898
#define INF 1000000000000
#define INFM -1000000000000
#define mod1 1000000007
#define mod2 998244353
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vint v;
    sort(a, a + n);
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (i == j)
        {
            v.pb(a[i]);
        }
        else
        {
            v.pb(a[i]);
            v.pb(a[j]);
        }
        i++;
        j--;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
