// codechef august lunchtime 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define pb push_back
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int arr[], int n)
{
    int cnt = 0;
    vi v;
    rep(i, n)
    {
        if (arr[i] == 0)
        {
            cnt++;
        }
        else
        {
            if (cnt > 0)
                v.pb(cnt);
            cnt = 0;
        }
    }

    sort(all(v), greater<int>());
    int m = v.size();
    if (m == 0)
    {
        cout << "No" << endl;
        return;
    }
    if (m == 1)
    {
        if (v[0] % 2 == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
        return;
    }

    if (m >= 2)
    {
        if (v[0] % 2 == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            int z = (v[0] + 1) / 2;
            if (z <= v[1])
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
        return;
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
        int arr[n];
        rep(i, n) cin >> arr[i];
        solve(arr, n);
    }

    return 0;
}