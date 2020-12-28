// count the number of non decreasing subarrays
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
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

ll solve(ll arr[], int n)
{
    ll cnt = 0;
    ll len = 1;

    loop(i, 0, n - 2)
    {
        if (arr[i] <= arr[i + 1])
        {
            len++;
        }
        else
        {
            cnt += (len) * (len - 1) / 2 + len;
            len = 1;
        }
    }

    if (len >= 1)
    {
        cnt += (len) * (len - 1) / 2 + len;
    }

    return cnt;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        rep(i, n)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n) << endl;
    }
    return 0;
}