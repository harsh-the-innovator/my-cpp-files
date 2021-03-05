// codechef starters div 3 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
#define pb push_back
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        string s;
        cin >> s;
        vl pos;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
                pos.pb(i);
        }

        ll cnt = 0;
        for (ll i = 0; i + 1 < pos.size(); i++)
        {
            if ((pos[i + 1] - pos[i] - 1) > c)
                cnt++;
        }
        if (!pos.empty() && ((n - pos.back() - 1 + pos[0]) > c))
            cnt++;
        if (cnt <= 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}