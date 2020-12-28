// codechef may 2020 long challenge
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
        int n = s.length();
        int i = 0;
        int count = 0;
        while (i <= n - 2)
        {
            if ((s[i] == 'x' && s[i + 1] == 'y') || (s[i] == 'y' && s[i + 1] == 'x'))
            {
                i += 2;
                count++;
            }
            else
            {
                i += 1;
            }
        }

        cout << count << endl;
    }
}