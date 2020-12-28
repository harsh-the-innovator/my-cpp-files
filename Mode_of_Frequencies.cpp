#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int arr[], int n)
{
    map<int, int> mp;
    rep(i, n)
    {
        mp[arr[i]]++;
    }

    map<int, int> freqCount;

    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        freqCount[itr->second]++;
    }

    int maxFreq = -1;
    for (auto itr = freqCount.begin(); itr != freqCount.end(); itr++)
    {
        maxFreq = max(maxFreq, itr->second);
    }
    int ans;
    for (auto itr = freqCount.begin(); itr != freqCount.end(); itr++)
    {
        if (maxFreq == itr->second)
        {
            cout << itr->first << endl;
            return;
        }
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        rep(i, n) cin >> arr[i];
        solve(arr, n);
    }

    return 0;
}