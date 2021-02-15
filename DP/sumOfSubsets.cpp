#include <bits/stdc++.h>
using namespace std;
void printSubset(int w[], int included[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (included[i])
        {
            cout << w[i] << " ";
        }
    }

    cout << endl;
}
bool subsetSum(int w[], int n, int m, int included[], int total, int remsum, int j)
{
    if (total == m)
    {
        return true;
    }

    for (int i = j; i < n; i++)
    {
        if (!included[i] && total + w[i] <= m && total + remsum > m)
        {
            total += w[i];
            included[i] = 1;
            remsum -= w[i];

            if (subsetSum(w, n, m, included, total, remsum, i + 1) == true)
            {
                return true;
            }

            included[i] = 0;
            total -= w[i];
        }
        remsum -= w[i];
    }
    return false;
}
void solve(int w[], int n, int m)
{
    int included[n] = {0};
    int total = 0;
    int remSum;
    for (int i = 0; i < n; i++)
    {
        remSum += w[i];
    }
    if (remSum < m)
    {
        cout << "Solution doesn't exist" << endl;
    }
    else
    {
        if (subsetSum(w, n, m, included, total, remSum, 0) == true)
        {
            printSubset(w, included, n);
        }
        else
        {
            cout << "false" << endl;
        }
    }
}
int main()
{
    int w[] = {10, 1, 2, 7, 6, 1, 5};
    int n = sizeof(w) / sizeof(w[0]);
    int requiredSum = 8;
    sort(w, w + n);

    solve(w, n, requiredSum);
}