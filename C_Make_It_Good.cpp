// codeforces #656 div2 C
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        rep(i, n) cin >> arr[i];

        int j = n - 1;
        while (j - 1 >= 0 && arr[j - 1] >= arr[j])
            j--;
        while (j - 1 >= 0 && arr[j - 1] <= arr[j])
            j--;

        cout << j << endl;
    }
    return 0;
}