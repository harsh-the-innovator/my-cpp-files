// codeforces #658 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define pb push_back
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);
int main()
{
    fast int t, n;
    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        vi result;
        rep(i, n)
        {
            if (a[i] != b[i])
            {
                if (i > 0)
                    result.pb(i + 1);
                result.pb(1);
                if (i > 0)
                    result.pb(i + 1);
            }
        }

        cout << result.size() << " ";
        for (auto x : result)
        {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}