#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
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
        ll arr[n];
        rep(i, n)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n, greater<ll>());
        unordered_set<ll> s;
        int flag = 0;
        ll OR = 0;
        rep(i, n)
        {
            OR = OR | arr[i];

            if (s.count(OR) > 0)
            {
                flag = 1;
                break;
            }
            s.insert(OR);
        }

        if (flag == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}