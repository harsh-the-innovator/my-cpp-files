// codeforces Round 91 B
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
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<pair<int, char>> v(3);
        v[0].ss = 'R';
        v[1].ss = 'S';
        v[2].ss = 'P';

        rep(i, s.length())
        {
            if (s[i] == 'R')
            {
                v[2].ff++;
            }
            if (s[i] == 'S')
            {
                v[0].ff++;
            }
            if (s[i] == 'P')
            {
                v[1].ff++;
            }
        }

        sort(all(v), greater<>());
        rep(i, s.length())
        {
            cout << v[0].ss;
        }
        cout << endl;
    }
    return 0;
}
