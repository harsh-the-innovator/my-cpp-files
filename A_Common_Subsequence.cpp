// codeforces #658 div 2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        rep(i, n)
        {
            cin >> a[i];
        }
        rep(i, m)
        {
            cin >> b[i];
        }

        unordered_set<int> s;

        rep(i, n)
        {
            s.insert(a[i]);
        }
        int flag = 0;

        rep(i, m)
        {
            if (s.find(b[i]) != s.end())
            {
                flag = 1;
                cout << "YES\n1 " << b[i] << endl;
                break;
            }
        }

        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}