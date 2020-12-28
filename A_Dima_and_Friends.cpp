// codeforces #167 div 2
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i, a, b) for (int i = a; i <= b; i++)
int main()
{
    int n, x;
    cin >> n;
    int t = n;
    int total = 0, cnt = 0;
    while (t--)
    {
        cin >> x;
        total += x;
    }

    loop(i, 1, 5)
    {
        if ((i + total - 1) % (n + 1) != 0)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}
