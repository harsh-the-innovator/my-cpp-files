// codeforces #661 div3
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(map<int, int> mp, int n) {
    int maxx = 0;

    loop(i, 2, 2*n) {
        int total = 0;
        for (auto x : mp) {
            int other = i - x.first;
            if (other>0 && mp.count(other)) {
                total+=min(x.second, mp[other]);
            }
        }

        total/=2;
        maxx = max(maxx, total);
    }

    cout<<maxx<<endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin>>n;
        map<int, int> mp;
        rep(i, n) {
            cin>>x;
            mp[x]++;
        }

        solve(mp, n);
    }

    return 0;
}