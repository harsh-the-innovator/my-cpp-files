#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    // #endif
    int n;
    cin >> n;
    stack<ll> s;
    stack<ll> maxEl;
    while (n--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            ll x;
            cin >> x;
            if (s.empty())
            {
                s.push(x);
                maxEl.push(x);
            }
            else
            {
                if (x > maxEl.top())
                {
                    maxEl.push(x);
                }
                else
                {
                    maxEl.push(maxEl.top());
                }
                s.push(x);
            }
        }
        if (q == 2)
        {
            s.pop();
            maxEl.pop();
        }
        if (q == 3)
        {
            cout << maxEl.top() << endl;
        }
    }
    return 0;
}
