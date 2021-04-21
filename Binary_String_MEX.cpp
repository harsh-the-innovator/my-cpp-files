#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);
#define rep(i, n) for (long long i = 0; i < n; i++)

bool isSubsequence(string str, string temp)
{
    if (str.length() == temp.length())
        return str == temp;

    ll itr1 = 0, itr2 = 0;
    while (itr1 < str.length() && itr2 < temp.length())
    {
        if (str[itr1] == temp[itr2])
        {
            itr1++;
            itr2++;
        }
        else
        {
            itr1++;
        }
    }

    if (itr2 < temp.length())
        return false;
    else
        return true;
}

string solve(string str)
{
    if (str == "0")
    {
        return "1";
    }

    queue<string> q;
    q.push("1");
    while (1)
    {
        string temp = q.front();
        q.pop();
        if (!isSubsequence(str, temp))
            return temp;

        string temp1 = temp;
        temp.push_back('0');
        temp1.push_back('1');
        q.push(temp);
        q.push(temp1);
    }
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool flag = false;
        rep(i, s.length())
        {
            if (s[i] == '0')
                flag = true;
        }
        if (flag == false)
        {
            cout << "0";
        }
        else
        {
            cout << solve(s);
        }
        cout << endl;
    }

    return 0;
}