// codechef august cook off challenge
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int a[], int n, int k)
{
    int i = 0;
    int ans = 0;
    while (i < n)
    {
        int j = i;
        int sum = 0;
        while (j < n && sum + a[j] <= k)
        {
            sum += a[j];
            j++;
        }
        if (j == i && sum + a[j] > k)
        {
            cout << "-1" << endl;
            return;
        }
        ans++;
        i = j;
    }

    cout << ans << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        rep(i, n) cin >> a[i];
        solve(a, n, k);
    }

    return 0;
}