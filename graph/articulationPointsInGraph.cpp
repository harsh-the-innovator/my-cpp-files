#include <bits/stdc++.h>
using namespace std;

void dfsTree(int u, vector<int> graph[], vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &visited, vector<bool> &ap)
{
    static int timer = 0;
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            //u--v is forward edge

            children++;

            parent[v] = u;
            dfsTree(v, graph, disc, low, parent, visited, ap);

            // Check if the subtree rooted with v has a
            // connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // u is an articulation point in following cases

            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == -1 && children > 1)
                ap[u] = true;

            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else if (parent[u] != v)
        {
            //then u---v is back edge
            //update the low value of u
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findArticulationPoints(vector<int> graph[], int V)
{
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> ap(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsTree(i, graph, disc, low, parent, visited, ap);
        }
    }

    //print articulation points
    for (int i = 0; i < V; i++)
    {
        if (ap[i] == true)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int main()
{
    int V, E, u, v;
    cin >> V >> E;

    vector<int> graph[V];
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    cout << "\nArticulation Points: \n";
    findArticulationPoints(graph, V);
}