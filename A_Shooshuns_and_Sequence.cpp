// codeforces #137 div2 A
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define vi vector<long long>
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (i = n - 1; i >= 0; i--)
#define loop(i, a, b) for (i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int32_t main()
{
    fast int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    k--;
    int temp = a[k];
    int i;
    loop(i, k, n - 1)
    {
        if (temp != a[i])
            break;
    }
    if (i == n)
    {
        int index = k-1, j;
        rrep(j, k) {
            if (temp!=a[j]) {
                index = j;
                break;
            }
        }
        if (j<0) {
            cout<<"0\n";
        }
        else {
            cout<<index+1<<endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}