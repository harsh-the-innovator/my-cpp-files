// codeforces round 91 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long

#define pb push_back
#define pair <int, int> pi
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

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
        int flag = 0;
        int i;
        for (i = 1; i <= n - 2; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl
                 << i << " " << i + 1 << " " << i + 2 << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}