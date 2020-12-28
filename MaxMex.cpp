// codechef june cook off div2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        set<ll> s;
        ll mcount = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < m)
            {
                s.insert(arr[i]);
            }

            if (arr[i] == m)
                mcount++;
        }

        if (s.size() == m - 1)
        {
            cout << n - mcount;
        }
        else
        {
            cout << "-1";
        }

        cout << endl;
    }
}