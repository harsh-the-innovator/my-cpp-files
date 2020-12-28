// codeforces #188 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast
        ll n,
        k;
    cin >> n >> k;
    ll evencnt = n / 2;
    ll oddcnt = n - evencnt;
    if (k <= oddcnt)
    {
        cout << 2 * k - 1 << endl;
    }
    else
    {
        cout << 2 * (k - oddcnt) << endl;
    }

    return 0;
}