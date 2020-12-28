// codechef october long challenge 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
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
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(ll a[], int n, ll x, int p, int k)
{
    p--;
    k--;
    int count = 0;
    if (k == p)
    {
        int i = p;
        if (x < a[p])
        {
            //move on to the left
            while (x < a[i])
            {
                count++;
                if (i > 0)
                    i--;
                else
                    break;
            }
            cout << count << endl;
        }
        else if (x == a[p])
        {
            cout << "0" << endl;
        }
        else
        {
            //move on to the right
            while (x > a[i])
            {
                count++;
                if (i < n - 1)
                    i++;
                else
                    break;
            }
            cout << count << endl;
        }
    }
    else if (k > p)
    {
        if (x > a[p])
        {
            cout << "-1" << endl;
        }
        else
        {
            int i = p;
            while (x < a[i])
            {
                count++;
                if (i > 0)
                    i--;
                else
                    break;
            }
            cout << count << endl;
        }
    }
    else
    {
        if (x < a[p])
        {
            cout << "-1" << endl;
        }
        else
        {
            int i = p;
            while (x > a[i])
            {
                count++;
                if (i < n - 1)
                    i++;
                else
                    break;
            }
            cout << count << endl;
        }
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, p, k;
        ll x;
        cin >> n >> x >> p >> k;
        ll a[n];
        rep(i, n) cin >> a[i];
        sort(a, a + n);
        solve(a, n, x, p, k);
    }

    return 0;
}