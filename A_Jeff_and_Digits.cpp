// codeforces #204 div2
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n;
    cin >> n;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    int zeroes = count(all(arr), 0);
    int fives = count(all(arr), 5);

    if (fives < 9)
    {
        if (zeroes > 0)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    else
    {
        if (zeroes > 0)
        {
            int cnt = fives / 9;
            while (cnt > 0)
            {
                cout << "555555555";
                cnt--;
            }
            for (int i = 1; i <= zeroes; i++)
            {
                cout << "0";
            }
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}