// Number of paths in a matrix with k coins gfg backtracking
// do it using dp because with backtracking time complexity is more

#include <bits/stdc++.h>
using namespace std;
#define N 200

bool isSafe(int mat[N][N], int i, int j, int n, int sum, int k)
{
    if (i >= 0 && j >= 0 && i < n && j < n && sum + mat[i][j] <= k)
    {
        return true;
    }

    return false;
}

void findTotalPaths(int mat[N][N], int n, int k, int &count, int i, int j, int sum)
{
    if (sum + mat[i][j] > k)
    {
        return;
    }

    if (i == n - 1 && j == n - 1 && sum + mat[i][j] == k)
    {
        count++;
        return;
    }

    if (isSafe(mat, i, j, n, sum, k))
    {
        findTotalPaths(mat, n, k, count, i, j + 1, sum + mat[i][j]);
        findTotalPaths(mat, n, k, count, i + 1, j, sum + mat[i][j]);
    }
}

void solve(int mat[N][N], int n, int k)
{
    int count = 0;
    int sum = 0;
    findTotalPaths(mat, n, k, count, 0, 0, sum);
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> x >> n;
        int mat[N][N];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        solve(mat, n, x);
    }
}