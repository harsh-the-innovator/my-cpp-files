// codeforces round #539 div2 A
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
#define all(c) cc.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fast int n, v;
    cin >> n >> v;
    int i = 1;
    int cost = 0;
    int tank = 0;
    while (i != n)
    {
        if (n - i <= v)
        {
            if (tank < n - i)
            {
                cost += i * (n - i - tank);
            }
            i = n;
        }
        else
        {

            cost += i * (v - tank);
            tank = v;
            i += 1;
            tank--;
        }
    }

    cout << cost << endl;
    return 0;
}