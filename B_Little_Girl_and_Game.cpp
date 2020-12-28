// codeforces #160 div2 B
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    string s;
    cin >> s;
    map<char, int> m;
    rep(i, s.length())
    {
        m[s[i]]++;
    }
    int k = 0;
    for (auto itr : m)
    {
        if (itr.second % 2 != 0)
        {
            k++;
        }
    }
    if (k == 0)
        cout << "First\n";
    else if (k == 1)
        cout << "First\n";
    else
    {
        if (k % 2 == 0)
            cout << "Second\n";
        else
            cout << "First\n";
    }
}