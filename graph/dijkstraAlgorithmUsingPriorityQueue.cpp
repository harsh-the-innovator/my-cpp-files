// using adjacency list and priority queue
// TIME COMPLEXITY = O(ElogV)
#include <bits/stdc++.h>
using namespace std;
#define iPair pair<int, int>
#define I INT_MAX

void printShortestDistances(vector<int> &dist, int V)
{
    cout << "Shortest Distance of all vertices from source:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

void dijkstraAlgo(vector<iPair> graph[], int V, int src)
{
    // creating a min heap
    //  pair of {distance,vertex}
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, I);
    pq.push({0, src});
    dist[src] = 0;

    // Looping till priority queue becomes empty(or all distances are not finalized)
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto i : graph[u])
        {
            int v = i.first;
            int weight = i.second;

            if (dist[u] != I && dist[u] + weight < dist[v])
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    printShortestDistances(dist, V);
}

void addWeightedEdge(vector<iPair> graph[], int u, int v, int w)
{
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main()
{
    int V, E, u, v, w;
    cin >> V >> E;

    // graph in the form of adjacency list
    vector<iPair> graph[V];
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        addWeightedEdge(graph, u, v, w);
    }

    dijkstraAlgo(graph, V, 0);
}