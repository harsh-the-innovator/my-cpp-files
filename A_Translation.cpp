// codeforces #40 div2 A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int i = 0;
    int j = n - 1;
    while (i <= n - 1 && j >= 0)
    {
        if (s[i] != t[j])
        {
            cout << "NO" << endl;
            return 0;
        }
        i++;
        j--;
    }

    cout << "YES" << endl;
}