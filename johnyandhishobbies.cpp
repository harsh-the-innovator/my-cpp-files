#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n + 1];
        set<ll> s;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }

        ll minK = 0;
        bool found = false;
        for (ll k = 1; k < 1024; k++)
        {
            bool flag = false;
            set<ll> newset;
            for (auto itr = s.begin(); itr != s.end(); itr++)
            {
                newset.insert(*itr);
            }

            for (ll i = 1; i <= n; i++)
            {
                ll val = k ^ a[i];
                if (newset.find(val) == newset.end())
                {
                    flag = true;
                    break;
                }
                else
                {
                    newset.erase(newset.find(val));
                }
            }

            if (flag == false)
            {
                found = true;
                minK = k;
                break;
            }
        }

        if (found)
            cout << minK << endl;
        else
            cout << "-1" << endl;
    }
}