// codeforces #129 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int n;
    cin >> n;
    vl arr(n);
    rep(i, n)
    {
        cin >> arr[i];
    }

    auto itr = min_element(arr.begin(), arr.end());
    ll cnt = count(arr.begin(), arr.end(), *itr);

    if (cnt == 1)
    {
        cout << itr - arr.begin() + 1 << endl;
    }
    else
    {
        cout << "Still Rozdil" << endl;
    }

    return 0;
}