#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX

struct Edge
{
    int src, dst, wt;
};

void printShortestDistances(vector<int> &dist, int V)
{
    cout << "Shortest Distance of all vertices from source:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

void bellmanAlgo(vector<Edge> &edgeList, int V, int E, int src)
{
    vector<int> dist(V, I);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        //relaxing all edges
        for (int i = 0; i < E; i++)
        {
            int u = edgeList[i].src;
            int v = edgeList[i].dst;
            int weight = edgeList[i].wt;

            if (dist[u] != I && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++)
    {
        int u = edgeList[i].src;
        int v = edgeList[i].dst;
        int weight = edgeList[i].wt;
        if (dist[u] != I && dist[u] + weight < dist[v])
        {
            cout << "Graph contains negative weighted cycle";
            return; // If negative cycle is detected, simply return
        }
    }

    printShortestDistances(dist, V);
}

int main()
{
    int V, E, u, v, w;
    cin >> V >> E;

    vector<Edge> edgeList(E);

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        edgeList[i] = {u, v, w};
    }

    bellmanAlgo(edgeList, V, E, 0);
}