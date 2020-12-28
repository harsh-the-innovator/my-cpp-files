// google kickstart Round D
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int ans = 0;
        int n;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (n == 1)
        {

            cout << "Case #" << j << ": 1" << endl;
        }
        else
        {
            int max = v[0];
            for (int i = 0; i < n; i++)
            {
                if (i == 0 && i + 1 < n)
                {
                    if (v[i] > v[i + 1])
                    {
                        ans++;
                    }
                }
                else if (i == n - 1)
                {
                    if (v[i] > max)
                    {
                        ans++;
                        max = v[i];
                    }
                }
                else
                {
                    if (v[i] > max && v[i] > v[i + 1])
                    {
                        ans++;
                        max = v[i];
                    }
                }
            }

            cout << "Case #" << j << ": " << ans << endl;
        }
    }
    return 0;
}