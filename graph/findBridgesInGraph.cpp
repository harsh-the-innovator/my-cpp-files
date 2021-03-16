#include <bits/stdc++.h>
using namespace std;

void dfsTree(int u, vector<int> graph[], vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &visited)
{
    static int timer = 0;

    visited[u] = true;

    disc[u] = low[u] = ++timer;

    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            //u--v is forward edge

            parent[v] = u;
            dfsTree(v, graph, disc, low, parent, visited);

            // Check if the subtree rooted with v has a
            // connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If the lowest vertex reachable from subtree
            // under v is  below u in DFS tree, then u-v
            // is a bridge
            if (low[v] > disc[u])
                cout << u << " " << v << endl;
        }
        else if (parent[u] != v)
        {
            //then u---v is back edge
            //update the low value of u
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges(vector<int> graph[], int V)
{
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    vector<int> disc(V);
    vector<int> low(V);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsTree(i, graph, disc, low, parent, visited);
        }
    }
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

    cout << "\nBridges in graph are: \n";
    findBridges(graph, V);
}