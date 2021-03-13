//TIME COMPLEXITY = O(V^2) for adjcency matrix
#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX

int minDistance(vector<int> &dist, vector<bool> &includedSet, int V)
{
    int min = I, minIndex;
    for (int i = 0; i < V; i++)
    {
        if (dist[i] <= min && !includedSet[i])
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printShortestDistances(vector<int> &dist, int V)
{
    cout << "Shortest Distance of all vertices from source:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

void dijkstraAlgo(vector<vector<int>> &graph, int V, int src)
{
    vector<int> dist(V, I);             //this will contain the final shortest distances of all vertices from source
    vector<bool> includedSet(V, false); // includedSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, includedSet, V);

        includedSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !includedSet[v] && dist[u] != I && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printShortestDistances(dist, V);
}

void addWeightedEdge(vector<vector<int>> &graph, int u, int v, int w)
{
    graph[u][v] = w;
    graph[v][u] = w;
}

int main()
{
    int V, E, u, v, w;
    cin >> V >> E;

    //making adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        addWeightedEdge(graph, u, v, w);
    }

    dijkstraAlgo(graph, V, 0);
}