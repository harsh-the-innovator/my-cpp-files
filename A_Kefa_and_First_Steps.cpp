// codeforces Round #321 div2
#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define loop(a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int maxLengthSubSegment(ll arr[], int n)
{
    int max = 1;
    int len = 1;
    loop(1, n - 1)
    {
        if (arr[i - 1] <= arr[i])
        {
            len++;
        }
        else
        {
            if (max < len)
                max = len;

            len = 1;
        }
    }

    if (max < len)
        max = len;
    return max;
}

int main()
{
    fast int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxLengthSubSegment(arr, n) << endl;
    return 0;
}