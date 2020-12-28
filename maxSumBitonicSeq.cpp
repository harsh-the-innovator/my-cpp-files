#include <iostream>
#include <climits>
using namespace std;
void solve()
{
    int n, max_sum = INT_MIN;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int msLeftToRight[n], msRightToLeft[n];

    for (int i = 0; i < n; i++)
    {
        msLeftToRight[i] = arr[i];
        msRightToLeft[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                msLeftToRight[i] = max(msLeftToRight[i], msLeftToRight[j] + arr[i]);
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
            {
                msRightToLeft[i] = max(msRightToLeft[i], msRightToLeft[j] + arr[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        max_sum = max(max_sum, (msLeftToRight[i] + msRightToLeft[i] - arr[i]));
    }

    cout << max_sum << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}