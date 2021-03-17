//codechef march long challenge 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int time[], int n, int h, int x)
{
    rep(i, n)
    {
        if (x + time[i] == h)
        {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

int main()
{
    fast int n, h, x;
    cin >> n >> h >> x;
    int time[n];
    rep(i, n) cin >> time[i];
    solve(time, n, h, x);
    cout << endl;

    return 0;
}