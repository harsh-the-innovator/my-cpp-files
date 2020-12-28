//codechef may 2020 lunchtime CONVSTR
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;
    int posA[26];
    memset(posA, -1, sizeof(posA));
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        if (posA[A[i] - 'a'] == -1)
        {
            posA[A[i] - 'a'] = i;
        }
    }
    vector<int> posB[26];
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            if (A[i] >= B[i])
            {
                posB[B[i] - 'a'].push_back(i);
            }
            else
            {
                flag = true;
                break;
            }
        }
    }

    if (flag == true)
    {
        cout << "-1" << endl;
    }
    else
    {
        bool flag1 = false;
        int steps = 0;
        for (int i = 25; i >= 0; i--)
        {
            if (posB[i].size() != 0)
            {

                // if element to convert is not prsent in A
                if (posA[i] == -1)
                {
                    flag1 = true;
                    break;
                }
                else
                {
                    posB[i].push_back(posA[i]);
                    sort(posB[i].begin(), posB[i].end());
                    res.push_back(posB[i]);
                    steps++;
                }
            }
        }
        if (flag1 == true)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << steps << endl;

            for (int i = 0; i < steps; i++)
            {
                cout << res[i].size() << " ";
                for (int j = 0; j < res[i].size(); j++)
                {
                    cout << res[i][j] << " ";
                }
                cout << endl;
            }
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
    }
}