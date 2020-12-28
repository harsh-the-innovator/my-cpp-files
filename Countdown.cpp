// google kickstart 2020 Round C
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
#define fast \
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fast int t;
    cin >> t;
    int i = 1;
    while (i <= t)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        rep(i, n)
        {
            cin >> arr[i];
        }
        int ans = 0;
        int counter = 0;
        loop(0, n - 2)
        {
            if (arr[i + 1] == arr[i] - 1)
            {
                counter++;
            }
            else
            {
                counter = 0;
            }

            if (arr[i + 1] == 1 && counter >= k - 1)
            {
                ans++;
            }
        }
        cout << "Case #" << i << ": " << ans << endl;
        i++;
    }
    return 0;
}