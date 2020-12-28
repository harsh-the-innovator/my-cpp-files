// codeforces #657 div2 A
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
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);
const string pattern = "abacaba";

bool contains(string s)
{
    int cnt = 0;
    loop(i, 0, s.length() - 7)
    {
        if (s.substr(i, 7) == pattern)
        {
            cnt++;
        }
    }
    return (cnt == 1);
}

void process(string s)
{

    rep(i, s.length())
    {
        if (s[i] == '?')
        {
            cout << "z";
        }
        else
        {
            cout << s[i];
        }
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (contains(s))
    {
        cout << "YES" << endl;
        process(s);
        return;
    }
    loop(i, 0, n - 7)
    {
        string str = s;
        bool flag = true;
        rep(j, 7)
        {
            if (str[i + j] != '?' && str[i + j] != pattern[j])
            {
                flag = false;
                break;
            }
            str[i + j] = pattern[j];
        }

        if (flag && contains(str))
        {
            cout << "YES" << endl;
            process(str);
            return;
        }
    }

    cout << "NO" << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}