// codeforces 2020 #650 div3
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int m;
        cin >> m;
        int b[m + 2];

        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }

        char t[m + 2]; //output

        sort(s.begin(), s.end());

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a']++; //storing counts of characters in string s
        }

        int j = n - 1;

        while (1)
        {
            vector<int> v;
            int count0 = 0;
            for (int i = 1; i <= m; i++)
            {
                // check for b[i]==0
                if (b[i] == 0)
                {
                    count0++;
                    v.push_back(i);
                }
            }

            if (count0 == 0)
                break;

            if (mp[s[j] - 'a'] < count0)
            {
                j = j - mp[s[j] - 'a'];
                continue;
            }

            int pointer = j;
            j = j - mp[s[j] - 'a'];

            for (int i = 1; i <= m; i++)
            {
                if (b[i] == 0)
                {
                    t[i] = s[pointer--];
                    b[i] = -1;
                }
                else
                {
                    for (int j = 0; j < v.size(); j++)
                    {
                        b[i] = b[i] - abs(i - v[j]);
                    }
                }
            }
        }

        for (int i = 1; i <= m; i++)
        {
            cout << t[i];
        }
        cout << endl;
    }
}