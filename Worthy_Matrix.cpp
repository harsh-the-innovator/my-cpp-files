#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define ll long long
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define loop(i, a, b) for (long long i = a; i <= b; i++)
#define fast \
    ios_base::sync_with_stdio(0), cin.tie(0);

void preComputation(vvl &arr, ll n, ll m)
{
    //prefix sum
    loop(i, 1, n)
    {
        ll sum = 0;
        loop(j, 1, m)
        {
            sum += arr[i][j];
            arr[i][j] = sum;
        }
    }
    loop(j, 1, m)
    {
        ll sum = 0;
        loop(i, 1, n)
        {
            sum += arr[i][j];
            arr[i][j] = sum;
        }
    }
}

ll findSum(vvl &arr, ll lower_i, ll lower_j, ll l)
{
    ll upper_i = lower_i + l - 1;
    ll upper_j = lower_j + l - 1;
    ll sum = arr[upper_i][upper_j];
    if (lower_i > 1 && lower_j > 1)
    {
        sum = sum - arr[lower_i - 1][upper_j] - arr[upper_i][lower_j - 1] + arr[lower_i - 1][lower_j - 1];
    }
    else
    {
        if (lower_i > 1)
        {
            sum -= arr[lower_i - 1][upper_j];
        }

        if (lower_j > 1)
        {
            sum -= arr[upper_i][lower_j - 1];
        }
    }

    return sum;
}

ll findMinIndex(vvl &arr, ll i, ll low, ll high, ll l, ll k)
{
    ll index = -1, mid;
    ll sum;

    sum = findSum(arr, i, low, l);
    if (sum >= k * l * l)
        return low;
    sum = findSum(arr, i, high, l);
    if (sum < k * l * l)
        return -1;

    while (low <= high && high >= 1)
    {
        mid = (low + high) / 2;
        //if sum is greater than equal to k*l*l move left to get smaller j;
        sum = findSum(arr, i, mid, l);
        if (sum >= k * l * l)
        {
            index = mid;
            high = mid - 1;
        }
        //else move right
        else
        {
            low = mid + 1;
        }
    }

    return index;
}

void solve(vvl &arr, ll n, ll m, ll k)
{
    int ans = 0;
    preComputation(arr, n, m);
    // //finding futher answer
    loop(l, 1, min(n, m))
    {
        loop(i, 1, n - l + 1)
        {
            ll j = findMinIndex(arr, i, 1, m - l + 1, l, k);
            if (j != -1)
            {
                ans += (m - l - j) + 2;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    fast int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vvl arr(n + 1, vl(m + 1));
        loop(i, 1, n)
        {
            loop(j, 1, m)
            {
                cin >> arr[i][j];
            }
        }

        solve(arr, n, m, k);
    }

    return 0;
}