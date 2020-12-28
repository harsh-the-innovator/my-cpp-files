// codeforces education round 93 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define pb push_back
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(string s, int n)
{
    vi a;
    int i = 0, count = 0;
    while (i < n)
    {
        count = 0;
        if (s[i] == '1')
        {
            int j = i;
            while (j < n && s[j] == '1')
            {
                count++;
                j++;
            }
            a.pb(count);
            i = j;
        }
        else
        {
            i++;
        }
    }

    sort(all(a), greater<int>());

    if (a.size() == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        int alice = 0;
        for (int i = 0; i < a.size(); i += 2)
        {
            alice += a[i];
        }
        cout << alice << endl;
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        solve(s, n);
    }

    return 0;
}