#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(string s, int n)
{

    loop(i, 1, n)
    {
        cout << s[n - 1];
    }
    cout << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }

    return 0;
}