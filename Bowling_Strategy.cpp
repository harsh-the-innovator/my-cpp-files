// september 2020 cook off
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

void solve(int n, int k, int l)
{
    if (k * l < n)
    {
        cout << "-1" << endl;
        return;
    }
    else if (n > 1 && k == 1)
    {
        cout << "-1" << endl;
        return;
    }
    else
    {
        int arr[n + 1];
        memset(arr, -1, sizeof(arr));
        int i = 1, j = 1;
        while (i <= n && l > 0)
        {
            arr[i] = j;
            i++;
            j++;
            if (j > k)
            {
                j = 1;
                l--;
            }
        }

        loop(i, 1, n)
        {
            cout << arr[i] << " ";
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
        int n, k, l;
        cin >> n >> k >> l;
        solve(n, k, l);
    }

    return 0;
}