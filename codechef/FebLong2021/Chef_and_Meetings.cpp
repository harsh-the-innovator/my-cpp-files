//codechef feb long challenge 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ps pair<string, string>
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

void convertInto24Hours(string &s)
{
    string hours = s.substr(0, 2);
    string status = s.substr(5, 2);

    if (status == "AM")
    {
        if (hours == "12")
        {
            s.replace(0, 2, "00");
        }
    }
    else if (status == "PM")
    {
        if (hours != "12")
        {
            string newNum = to_string(stoi(hours) + 12);
            s.replace(0, 2, newNum);
        }
    }
    s.erase(5, 2);
}

void solve(vector<ps> &vp, int n, string p)
{
    convertInto24Hours(p);
    int phours = stoi(p.substr(0, 2));
    int pmins = stoi(p.substr(3, 2));

    string res = "";
    for (auto el : vp)
    {
        string l = el.first;
        string r = el.second;
        convertInto24Hours(l);
        convertInto24Hours(r);

        int lhours = stoi(l.substr(0, 2));
        int lmins = stoi(l.substr(3, 2));
        int rhours = stoi(r.substr(0, 2));
        int rmins = stoi(r.substr(3, 2));

        if (phours > lhours && phours < rhours)
        {
            res.push_back('1');
        }
        else if (phours == lhours && phours == rhours)
        {
            if (pmins >= lmins && pmins <= rmins)
            {
                res.push_back('1');
            }
            else
            {
                res.push_back('0');
            }
        }
        else if (phours == lhours)
        {
            if (pmins >= lmins)
            {
                res.push_back('1');
            }
            else
            {
                res.push_back('0');
            }
        }
        else if (phours == rhours)
        {
            if (pmins <= rmins)
            {
                res.push_back('1');
            }
            else
            {
                res.push_back('0');
            }
        }
        else
        {
            res.push_back('0');
        }
    }
    cout << res << endl;
}

string takeInput(void)
{
    char c;
    string s;
    rep(i, 7)
    {
        cin >> c;
        s.push_back(c);
    }

    return s;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        string p;
        int n;
        char c;
        p = takeInput();
        cin >> n;

        vector<ps> vp;
        string l, r;
        rep(i, n)
        {
            l = takeInput();
            r = takeInput();
            vp.push_back({l, r});
        }

        solve(vp, n, p);
    }

    return 0;
}