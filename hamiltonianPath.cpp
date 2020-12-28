#include <bits/stdc++.h>
using namespace std;
#define D 11

bool isSafe(bool graph[D][D], int n, int path[], int pos, int v)
{

    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 1; i <= n; i++)
    {
        if (path[i] == v)
        {
            return false;
        }
    }

    return true;
}

bool findPath(bool graph[D][D], int n, int path[], int pos)
{
    if (pos > n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (path[i] == -1)
            {
                return false;
            }
        }
        return true;
    }

    for (int v = 1; v <= n; v++)
    {
        if (isSafe(graph, n, path, pos, v))
        {
            path[pos] = v;

            if (findPath(graph, n, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

void solve(bool graph[D][D], int n)
{
    int path[n + 1];
    memset(path, -1, sizeof(path));

    for (int i = 1; i <= n; i++)
    {
        path[1] = i;
        if (findPath(graph, n, path, 2))
        {
            cout << "1" << endl;
            return;
        }
    }
    cout << "0" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v;
        cin >> n >> m;
        bool graph[D][D];
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        solve(graph, n);
    }
}