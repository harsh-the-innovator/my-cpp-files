// codechef july 2020 long challenge div 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        map<ll, ll> XCoord, YCoord;
        int n;
        cin >> n;
        ll x, y;
        for (int i = 1; i <= 4 * n - 1; i++)
        {
            cin >> x >> y;
            XCoord[x]++;
            YCoord[y]++;
        }

        ll missingX, missingY;
        for (auto itr = XCoord.begin(); itr != XCoord.end(); itr++)
        {
            if (itr->second % 2 != 0)
            {
                missingX = itr->first;
                break;
            }
        }
        for (auto itr = YCoord.begin(); itr != YCoord.end(); itr++)
        {
            if (itr->second % 2 != 0)
            {
                missingY = itr->first;
                break;
            }
        }

        cout << missingX << " " << missingY << endl;
    }
}