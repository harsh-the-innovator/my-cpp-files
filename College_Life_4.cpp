//codechef march long challenge 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define loop(i, a, b) for (long long i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

ll solve(ll n, ll eggs, ll bars, ll omeletteCost, ll shakeCost, ll cakeCost)
{
    ll ans = LONG_MAX;
    loop(cakes, 0, n)
    {
        if (eggs < cakes || bars < cakes)
            break;

        ll omelettes = (eggs - cakes) / 2;
        ll shakes = (bars - cakes) / 3;

        if (omelettes + shakes + cakes < n)
            continue;

        ll omeletteReq, shakesReq;
        if (omeletteCost < shakeCost)
        {
            omeletteReq = min(omelettes, n - cakes);
            shakesReq = n - cakes - omeletteReq;
        }
        else
        {
            shakesReq = min(shakes, n - cakes);
            omeletteReq = n - cakes - shakesReq;
        }

        ll price = cakes * cakeCost + omeletteReq * omeletteCost + shakesReq * shakeCost;

        ans = min(ans, price);
    }

    if (ans == LONG_MAX)
        return -1;
    else
        return ans;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        ll n, e, h, a, b, c;
        cin >> n >> e >> h >> a >> b >> c;

        if (e == 0 && h == 0)
        {
            cout << "-1" << endl;
            continue;
        }

        ll ans = solve(n, e, h, a, b, c);
        cout << ans << endl;
    }

    return 0;
}