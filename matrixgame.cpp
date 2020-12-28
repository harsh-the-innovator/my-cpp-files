// codeforces #648 div2 A
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int arr[][50], int n, int m)
{

    // check for row
    for (int k = 0; k < m; k++)
    {
        if (arr[i][k] == 1 && k != j)
        {
            return false;
        }
    }

    // check for column
    for (int k = 0; k < n; k++)
    {
        if (arr[k][j] == 1 && k != i)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n][50];
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 0)
                {
                    v.push_back({i, j});
                }
            }
        }

        int turn = 0; // means turn is of ashish
        int winner[] = {0, 0};
        for (int i = 0; i < v.size(); i++)
        {
            int first = v[i][0];
            int second = v[i][1];
            if (isSafe(first, second, arr, n, m))
            {
                arr[first][second] = 1;
                winner[turn] = 1;
                turn = turn ? 0 : 1;
                winner[turn] = 0;
            }
            else
            {
                winner[turn] = 0;
                continue;
            }
        }

        if (turn == 0 && winner[0] == 0)
            cout << "Vivek" << endl;
        else if (turn == 1 && winner[1] == 0)
            cout << "Ashish" << endl;
        else
        {
        }
    }

    return 0;
}