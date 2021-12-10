// codeforces global round 90 div2 B
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int c0 = 0, c1 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                c0++;
            if (s[i] == '1')
                c1++;
        }

        min(c0, c1) % 2 != 0 ? cout << "DA" : cout << "NET";
        cout << endl;
    }
}

// cout<<"hello"