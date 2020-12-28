// codeforces Round #261 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define vl vector<long long>
#define all(c) c.begin(), c.end()
#define rep(i, n) for (long long i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int32_t main()
{
    fast int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    auto minIndex = min_element(all(a));
    auto maxIndex = max_element(all(a));

    int c1 = count(all(a), *minIndex);
    int c2 = count(all(a), *maxIndex);

    if (*maxIndex == *minIndex)
    {
        cout << "0"
             << " " << (c1 * (c1 - 1)) / 2 << endl;
    }
    else
    {
        cout << (*maxIndex - *minIndex) << " " << c1 * c2 << endl;
    }

    return 0;
}