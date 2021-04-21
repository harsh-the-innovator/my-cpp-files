#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define loop(i, a, b) for (long long i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

ll solve(ll n)
{
    if (n == 1)
        return 20;
    if (n == 2)
        return 36;
    if (n == 3)
        return 51;
    if (n == 4)
        return 60;

    ll ans;
    ll q = n / 4;
    ll rem = n % 4;
    if (rem == 0)
    {
        ans = 60 + 44 * (q - 1);
    }
    if (rem == 1)
    {
        ans = 60 + 44 * (q - 1) + 16;
    }
    if (rem == 2)
    {
        ans = 60 + 44 * (q - 1) + 28;
    }
    if (rem == 3)
    {
        ans = 60 + 44 * (q - 1) + 39;
    }

    return ans;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}