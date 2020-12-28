// codeforces beta round #89 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int n;
    cin >> n;
    int r = 2 * n + 1, k;
    for (int i = 1; i <= n + 1; i++)
    {
        k = 0;
        for (int j = 1; j <= n + i; j++)
        {
            if (j >= n + 2 - i && j <= n + i)
            {
                if (j == n + i)
                {
                    cout << k;
                }
                else
                {
                    cout << k << " ";
                }
                if (j < n + 1)
                    k++;
                else
                    k--;
            }
            else
            {

                cout << "  ";
            }
        }
        cout << endl;
    }

    for (int i = n + 2; i <= r; i++)
    {
        k = 0;
        for (int j = 1; j <= 3 * n + 2 - i; j++)
        {
            if (j >= i - n && j <= 3 * n + 2 - i)
            {
                if (j == 3 * n + 2 - i)
                {
                    cout << k;
                }
                else
                {
                    cout << k << " ";
                }
                if (j < n + 1)
                    k++;
                else
                    k--;
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}