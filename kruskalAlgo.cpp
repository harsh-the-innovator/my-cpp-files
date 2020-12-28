#include <bits/stdc++.h>
using namespace std;

#define I INT_MAX

int edges[3][7] = {{1, 1, 2, 2, 2, 3, 4},
                   {2, 4, 3, 4, 5, 5, 5},
                   {2, 6, 3, 8, 5, 7, 9}};

int myset[6] = {-1, -1, -1, -1, -1, -1};
int included[7]{0};
int storeEdges[2][4];

void Union(int u, int v)
{
    if (myset[u] < myset[v])
    {
        myset[u] += myset[v];
        myset[v] = u;
    }
    else
    {
        myset[v] += myset[u];
        myset[u] = v;
    }
}

int find(int u)
{
    int x = u, v = 0;
    while (myset[x] > 0)
    {
        x = myset[x];
    }
    while (u != x)
    {
        v = myset[u];
        myset[u] = x;
        u = v;
    }

    return x;
}

int main()
{
    int i, j, k, u, v, min = I, e = 7, n = 5;
    int minCost = 0;
    i = 0;
    while (i < n - 1)
    {
        min = I;
        for (j = 0; j < e; j++)
        {
            if (included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        if (find(u) != find(v))
        {
            storeEdges[0][i] = u;
            storeEdges[1][i] = v;
            Union(find(u), find(v));
            i++;
        }

        included[k] = 1;
        minCost += edges[2][k];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << "(" << storeEdges[0][i] << "," << storeEdges[1][i] << ")" << endl;
    }

    cout << "MIN COST = " << minCost << endl;
}