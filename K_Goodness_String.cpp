//google kickstart round A 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(string s, int n, int k)
{
    int initialScore = 0;
    int count = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (s[i - 1] != s[n - i])
            initialScore++;
        else
            count++;

        if (initialScore >= k)
        {
            cout << "0";
            return;
        }
    }

    if (initialScore + count >= k)
    {
        cout << min(count, k - initialScore);
    }
    else
        cout << "-1";
}

int main()
{
    fast int t;
    cin >> t;
    loop(i, 1, t)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        cout << "Case #" << i << ": ";
        solve(s, n, k);
        cout << endl;
    }

    return 0;
}