//codechef march long challenge 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int a[], int n)
{
    sort(a, a + n);
    bool isInvalid = false;
    rep(i, n)
    {
        if (a[i] > (i + 1))
        {
            isInvalid = true;
            break;
        }
    }

    if (isInvalid)
    {
        cout << "Second";
        return;
    }
    ll sum = 0;

    rep(i, n)
    {
        sum += (i + 1) - a[i];
    }

    if (sum % 2 == 0)
    {
        cout << "Second";
    }
    else
    {
        cout << "First";
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
        int a[n];
        rep(i, n) cin >> a[i];

        solve(a, n);
        cout << endl;
    }

    return 0;
}