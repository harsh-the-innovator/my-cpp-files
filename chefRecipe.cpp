// 2020 codechef may cook off CHEFRECP
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int freq[1001]{0};
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int unique[1001]{0};
    for (int i = 0; i < 1001; i++)
    {
        if (freq[i] > 0)
        {
            unique[freq[i]]++;
        }
    }

    for (int i : unique)
    {
        if (i > 1)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << "NO";
    }
    else
    {
        bool visited[1001]{false};
        visited[arr[0]] = true;
        int i = 0;
        for (i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                continue;

            if (visited[arr[i]])
            {
                break;
            }

            visited[arr[i]] = true;
        }

        if (i == n)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}