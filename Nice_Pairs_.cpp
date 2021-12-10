#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

void solve(string s, int n)
{
    int ans = 0;
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;

    loop(i, 1, n)
    {
        int sum = (s[i - 1] - '0') + i;
        int diff = (s[i - 1] - '0') - i;
        mp1[sum]++;
        mp2[diff]++;
    }

    for (auto itr : mp1)
    {
        if (itr.second > 1)
        {
            ans += ((itr.second) * (itr.second - 1)) / 2;
        }
    }

    for (auto itr : mp2)
    {
        if (itr.second > 1)
        {
            ans += ((itr.second) * (itr.second - 1)) / 2;
        }
    }

    cout << ans << endl;
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