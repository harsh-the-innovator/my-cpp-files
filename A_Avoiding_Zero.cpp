// codeforces global round 11, 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
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

void solve(vi arr, int n)
{
    int sum = 0;
    rep(i, n)
    {
        sum += arr[i];
    }

    if (sum == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        if (sum > 0)
        {
            sort(all(arr), greater<int>());
            for (auto i : arr)
            {
                cout << i << " ";
            }
        }
        else
        {
            sort(all(arr));
            for (auto i : arr)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        rep(i, n) cin >> arr[i];
        solve(arr, n);
    }

    return 0;
}