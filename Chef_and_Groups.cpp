//codechef march long challenge 2021
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int solve(string s, int n)
{
    int i = 0, j;
    int count = 0;
    while (i < n)
    {
        if (s[i] == '1')
        {
            count++;
            j = i + 1;
            while (j < n && s[j] != '0')
            {
                j++;
            }

            i = j;
        }
        else
        {
            i++;
        }
    }

    return count;
}

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        cout << solve(s, n) << endl;
    }

    return 0;
}