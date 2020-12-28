// codeforces #663 div2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
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
        cin>>n>>m;
        char x;
        int ans=0;
        loop(i, 1, n) {
            loop(j, 1, m) {
                cin>>x;
                if (i==n && j!=m) {
                    if (x=='D') ans++;
                }
                else if (i!=n && j==m) {
                    if (x=='R') ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}