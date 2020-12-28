#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = INT_MAX;
    sort(arr, arr + n);
    for (int i = 0; i <= n - 2; i++)
    {

        if ((arr[i] >= 0 && arr[i + 1] >= 0) || (arr[i] <= 0 && arr[i + 1] <= 0))
        {
            if (abs(arr[i] - arr[i + 1]) < min)
            {
                min = abs(arr[i] - arr[i + 1]);
            }
        }
    }

    cout << min << endl;
}