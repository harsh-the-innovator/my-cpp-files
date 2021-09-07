#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int g1, s1, b1, g2, s2, b2;
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;
        if ((g1 + s1 + b1) > (g2 + s2 + b2))
        {
            cout << "1";
        }
        else
        {
            cout << "2";
        }
        cout << endl;
    }

    return 0;
}