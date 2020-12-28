// codechef august long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int findMinInefficiency(int a[], int n, int k)
{
    int dp[n + 1];
    dp[0] = 0;
    loop(i, 1, n)
    {
        dp[i] = dp[i - 1] + k;
        int clash = 0;
        map<int, int> mp;

        for (int j = i; j >= 1; j--)
        {
            mp[a[j]]++;

            if (mp[a[j]] == 2)
                clash += 2;
            else if (mp[a[j]] > 2)
                clash += 1;

            dp[i] = min(dp[i], dp[j - 1] + k + clash);
        }
    }

    return dp[n];
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        loop(i, 1, n) cin >> a[i];
        cout << findMinInefficiency(a, n, k) << endl;
    }

    return 0;
}