#include <bits/stdc++.h>
using namespace std;
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

void solve(stack<ll> s1, stack<ll> s2, ll x)
{
    ll sum = 0;
    int cnt = 0;

    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() < s2.top() && sum + s1.top() <= x)
        {
            sum += s1.top();
            s1.pop();
        }
        else if (s1.top() >= s2.top() && sum + s2.top() <= x)
        {
            sum += s2.top();
            s2.pop();
        }
        else
            break;
        cnt++;
    }

    if (sum > x)
        cout << cnt << endl;
    else
    {
        while (!s1.empty() && sum + s1.top() <= x)
        {
            sum += s1.top();
            s1.pop();
            cnt++;
        }
        while (!s2.empty() && sum + s2.top() <= x)
        {
            sum += s2.top();
            s2.pop();
            cnt++;
        }
        cout << cnt << endl;
    }
}

int main()
{
    int g;
    cin >> g;
    while (g--)
    {
        int n, m;
        ll x;
        cin >> n >> m >> x;
        ll a[n];
        ll b[m];
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];
        stack<ll> s1, s2;
        rrep(i, n)
        {
            s1.push(a[i]);
        }
        rrep(i, m)
        {
            s2.push(b[i]);
        }
        solve(s1, s2, x);
    }
}