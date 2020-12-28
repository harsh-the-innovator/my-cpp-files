// google kickstart 2020 Round D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0);
int main()
{
    fast int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        ll n;
        cin >> n;
        ll arr[n];
        char note[4]{'A', 'B', 'C', 'D'};
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll ans = 0;
        ll ptr = 0;
        for (ll i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                if (note[ptr] == 'D')
                {
                    ans++;
                    ptr = 0;
                }
                else
                {
                    ptr++;
                }
            }
            else if (arr[i] > arr[i - 1])
            {
                if (note[ptr] == 'A')
                {
                    ptr = 3;
                    ans++;
                }
                else
                {
                    ptr--;
                }
            }
        }

        cout << "Case #" << j << ": " << ans << endl;
    }
}