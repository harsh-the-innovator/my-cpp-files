// may 2020 long challenge codechef
#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve()
{
    ll n, q;
    string s;
    ll c;
    cin >> n >> q;
    cin >> s;
    unordered_map<char, int> m;
    for (ll i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    while (q--)
    {
        cin >> c;
        ll count = 0;
        for (auto itr = m.begin(); itr != m.end(); itr++)
        {

            if (itr->second - c > 0)
            {
                count += itr->second - c;
            }
        }
        cout << count << endl;
    }
}
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}