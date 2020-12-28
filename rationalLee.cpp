// codeforces #652 div2 B

#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), w(k);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> w[i];
        }

        sort(a.begin(), a.end());
        sort(w.rbegin(), w.rend());
        ll happiness = 0;
        for (int i = k - 1; i >= 0 && w[i] == 1; i--)
        {
            happiness += 2 * a.back();
            a.pop_back();
            w.pop_back();
            n--;
            k--;
        }

        for (int i = n - k; i < n; i++)
        {
            happiness += a[i];
        }

        int p = 0;
        for (int i = 0; i < k; i++)
        {
            happiness += a[p];
            p += w[i] - 1;
        }

        cout << happiness << endl;
    }
}