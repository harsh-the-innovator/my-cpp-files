// codeforces #650 2020 div3
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string b;
    cin >> b;
    int n = b.length();
    int numsubstr = n / 2;
    vector<string> v;
    for (int i = 0; i < n; i += 2)
    {
        string s = b.substr(i, 2);
        v.push_back(s);
    }
    string a = "";
    for (int i = 0; i < numsubstr - 1; i++)
    {
        a = a + v[i][0];
    }
    a += v[numsubstr - 1];
    cout << a << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}