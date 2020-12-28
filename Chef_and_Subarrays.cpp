#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

ll rangeFreq[32];

ll getOrSum()
{
    ll number = 0;
    rep(i, 32)
    {
        if (rangeFreq[i])
        {
            number += (1 << i);
        }
    }

    return number;
}

void addBitsToRange(int num)
{
    rep(i, 32)
    {
        if (num & (1 << i))
            rangeFreq[i]++;
    }
}

void removeBitsInRange(int num)
{
    rep(i, 32)
    {
        if (num & (1 << i))
            rangeFreq[i]--;
    }
}

void solve(ll arr[], int n, ll k)
{
    memset(rangeFreq, 0, sizeof(rangeFreq));

    ll ans = 0;
    int j = 0;
    rep(i, n)
    {
        while (j < n && getOrSum() < k)
        {
            addBitsToRange(arr[j]);
            j++;
        }

        if (getOrSum() >= k)
        {
            ans += n - j + 1;
        }
        removeBitsInRange(arr[i]);
    }

    cout << ans << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        ll arr[n];
        rep(i, n) cin >> arr[i];
        solve(arr, n, k);
    }

    return 0;
}