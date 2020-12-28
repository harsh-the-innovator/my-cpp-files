// codechef july lunchtime 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
#define pb push_back
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll k;
        cin >> k;
        vl arr(n);
        string ans = "";
        rep(i, n)
        {
            cin >> arr[i];
        }

        rep(i, n)
        {
            if (arr[i] % k == 0)
            {
                ans.pb('1');
            }
            else
            {
                ans.pb('0');
            }
        }

        cout << ans << endl;
    }
    return 0;
}