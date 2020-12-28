// codeforces round #135 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int k;
    string s;
    cin >> k >> s;
    map<char, int> cnt;
    rep(i, s.length())
    {
        cnt[s[i]]++;
    }
    int flag = 1;
    for (auto itr : cnt)
    {
        if (itr.second % k != 0)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
    {
        cout << "-1";
    }
    else
    {
        string ans = "";
        for (auto itr : cnt)
        {
            int count = itr.second / k;
            while (count--)
            {
                ans += itr.first;
            }
        }
        rep(i, k)
        {
            cout << ans;
        }
    }

    cout << endl;

    return 0;
}