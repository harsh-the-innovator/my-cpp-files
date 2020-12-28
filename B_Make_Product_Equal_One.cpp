// codeforces #580 div 2 B
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fast int n;
    cin >> n;
    ll arr[n];
    rep(i, n)
    {
        cin >> arr[i];
    }
    ll minCoins = 0;
    rep(i, n)
    {
        if (arr[i] < -1)
        {
            minCoins += (-1 - arr[i]);
            arr[i] = -1;
        }
        else if (arr[i] > 1)
        {
            minCoins += (arr[i] - 1);
            arr[i] = 1;
        }
    }

    int neg = 0, zero = 0;
    rep(i, n)
    {
        if (arr[i] == -1)
            neg++;
        else if (arr[i] == 0)
            zero++;
    }

    if (zero > 0)
    {
        minCoins += zero;
    }
    else
    {
        if (neg % 2 != 0)
        {
            minCoins += 2;
        }
    }

    cout << minCoins << endl;

    return 0;
}