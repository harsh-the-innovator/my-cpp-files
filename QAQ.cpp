// codeforces Round #447 div2 A. QAQ
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = i + 1; j <= n - 2; j++)
        {
            for (int k = j + 1; k <= n - 1; k++)
            {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                    count++;
            }
        }
    }
    cout << count << endl;
}