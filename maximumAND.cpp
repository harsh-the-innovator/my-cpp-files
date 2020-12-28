// codechef june lunchtime 2020 div2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
    if (p1.first < p2.first)
    {
        return false;
    }
    else if (p1.first == p2.first)
    {
        if (p1.second > p2.second)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<pair<ll, ll>> b(31);
        for (int i = 0; i <= 30; i++)
        {
            ll count = 0;
            for (int j = 0; j < n; j++)
            {
                if (v[j] & (ll)(pow((ll)2, (ll)i)))
                    count++;
            }

            b[i].second = i;                        //storing index
            b[i].first = count * pow((ll)2, (ll)i); //storing contribution
        }

        sort(b.begin(), b.end(), cmp);

        ll result = 0;
        for (int i = 0; i < k; i++)
        {
            result += pow((ll)2, (ll)b[i].second);
        }
        cout << result << endl;
    }
}