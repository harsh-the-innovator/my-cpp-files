// codechef starters 2021 div3

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
        int d, c;
        cin >> d >> c;
        int a1, a2, a3, b1, b2, b3;
        cin >> a1 >> a2 >> a3;
        cin >> b1 >> b2 >> b3;

        int cost1 = a1 + a2 + a3;
        int cost2 = b1 + b2 + b3;

        int total = cost1 + cost2 + 2 * d;
        int newTotal = cost1 + cost2 + c;

        if (cost1 < 150)
        {
            newTotal += d;
        }
        if (cost2 < 150)
        {
            newTotal += d;
        }

        if (newTotal < total)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}