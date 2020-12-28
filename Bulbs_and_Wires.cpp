// sept cook off 2020
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define pb push_back
#define all(c) c.begin(), c.end()
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void solve(int n, int k, string s)
{

    // if k==0:
    if (k == 0)
    {
        int cnt = 0;
        loop(i, 0, n)
        {
            if (s[i] == '0')
                cnt++;
        }
        cout << cnt << endl;
        return;
    }

    // check if all zero:
    int flag = 0;
    loop(i, 0, n)
    {
        if (s[i] == '1')
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "0" << endl;
        return;
    }

    // check if all one:
    flag = 0;
    loop(i, 0, n)
    {
        if (s[i] == '0')
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "0" << endl;
        return;
    }

    // mage zero groups
    vector<int> zmid, zside;
    int i = 0;
    while (i < n)
    {
        if (i == 0 && s[0] == '0')
        {
            int j = 0;
            while (s[j] == '0' && j < n)
            {
                j++;
            }
            zside.pb(j);
            i = j;
        }
        else
        {
            if (s[i] == '0')
            {
                int j = i;
                while (s[j] == '0' && j < n)
                {
                    j++;
                }
                if (j == n)
                {
                    zside.pb(j - i);
                }
                else
                {
                    zmid.pb(j - i);
                }
                i = j;
            }
            else
            {
                i++;
            }
        }
    }

    sort(all(zmid), greater<int>());
    sort(all(zside), greater<int>());

    int total = 0;
    for (auto itr : zmid)
    {
        total += itr;
    }
    for (auto itr : zside)
    {
        total += itr;
    }

    int gcuts = 0;
    if (k % 2 != 0)
    {
        k--;
        if (zside.size() != 0)
        {
            gcuts += zside[0];
            zside.erase(zside.begin());
        }
    }

    while (zmid.size() != 0)
    {
        if (k > 2)
        {
            gcuts += zmid[0];
            k -= 2;
            zmid.erase(zmid.begin());
        }
        else
        {
            break;
        }
    }

    if (k >= 2)
    {
        int sum = 0;
        for (auto itr : zside)
        {
            sum += itr;
        }
        if (zmid.size() != 0)
        {
            gcuts += max(zmid[0], sum);
        }
        else
        {
            gcuts += sum;
        }
    }
    cout << total - gcuts << endl;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        solve(n, k, s);
    }

    return 0;
}