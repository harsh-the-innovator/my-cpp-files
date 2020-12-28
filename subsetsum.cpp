// backtracking
#include <bits/stdc++.h>
using namespace std;
void printSol(set<vector<int>> s)
{
    for (auto i : s)
    {
        for (auto el : i)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}
void subsetSum(int w[], int n, int m, int included[], int total, int remsum, int j, set<vector<int>> &s)
{
    if (total == m)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (included[i])
            {
                temp.push_back(w[i]);
            }
        }

        s.insert(temp);
        return;
    }

    for (int i = j; i < n; i++)
    {
        if (!included[i] && total + w[i] <= m && total + remsum > m)
        {
            total += w[i];
            included[i] = 1;
            remsum -= w[i];

            subsetSum(w, n, m, included, total, remsum, i + 1, s);

            included[i] = 0;
            total -= w[i];
        }
        remsum -= w[i];
    }
}
void solve(int w[], int n, int m)
{
    int included[n] = {0};
    int total = 0;
    int remSum;
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        remSum += w[i];
    }
    if (remSum < m)
    {
        cout << "Empty" << endl;
    }
    else
    {
        subsetSum(w, n, m, included, total, remSum, 0, s);
        if (s.size() == 0)
        {
            cout << "Empty" << endl;
        }
        else
        {
            printSol(s);
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