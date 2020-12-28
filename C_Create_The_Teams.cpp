// codeforces Round 91 C
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll a[n], i, j;
        for (i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll ans = 0, size = 0;
        for (i = n - 1; i >= 0; i--)
        {
            if (a[i] >= x)
                ans++;
            else
            {
                size = 1;
                for (j = i - 1; j >= 0; j--)
                {
                    size++;
                    if (a[j] * size >= x)
                        break;
                }
                if (j >= 0)
                {
                    i = j;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}