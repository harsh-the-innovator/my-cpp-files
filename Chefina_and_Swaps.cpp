// codechef july 2020 long challenge div 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int main()
{
    fastIO
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], b[n];
        map<ll, ll> count1, count2;
        set<ll> s;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            count1[a[i]]++;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            count2[b[i]]++;
        }

        for (ll i = 0; i < n; i++)
        {
            s.insert(a[i]);
            s.insert(b[i]);
        }

        bool flag = false;
        ll x, y;
        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            x = *itr;
            if ((count1[x] + count2[x]) % 2 != 0)
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
            }
        }

        if (flag == false)
        {
            cout << "-1" << endl;
        }
        else
        {
            bool allZero = false;
            for (auto itr = s.begin(); itr != s.end(); itr++)
            {
                x = *itr;
                if (count1[x] == count2[x])
                {
                    allZero = true;
                }
                else
                {
                    allZero = false;
                    break;
                }
            }

            if (allZero == true)
            {
                cout << "0" << endl;
            }
            else
            {
                // find min cost of swaps
                vector<ll> A, B;
                ll cost = 0;
                for (auto itr : count1)
                {
                    x = itr.first;
                    y = itr.second;
                    if (count2.find(x) != count2.end())
                    {
                        ll dx = min(y, count2[x]);
                        count1[x] -= dx;
                        count2[x] -= dx;
                    }
                }

                for (auto itr : count1)
                {
                    x = itr.first;
                    y = itr.second;
                    for (int i = 0; i < y / 2; i++)
                    {
                        A.push_back(x);
                    }
                }

                for (auto itr : count2)
                {
                    x = itr.first;
                    y = itr.second;
                    for (int i = 0; i < y / 2; i++)
                    {
                        B.push_back(x);
                    }
                }

                reverse(B.begin(), B.end());

                for (int i = 0; i < A.size(); i++)
                {
                    cost += min(*s.begin() * 2, min(A[i], B[i]));
                }

                cout << cost << endl;
            }
        }
    }
}