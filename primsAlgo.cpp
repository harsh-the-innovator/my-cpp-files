#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
int minWeightIndex(int weight[], bool visited[], int V)
{
    int min = I, minIndex;

    for (int v = 0; v < V; v++)
        if (!visited[v] && weight[v] < min)
            min = weight[v], minIndex = v;

    return minIndex;
}
int spanningTree(int V, int E, vector<vector<int>> &graph)
{

    bool visited[V];
    memset(visited, false, sizeof(visited));
    int parent[V];
    int weight[V];

    for (int i = 0; i < V; i++)
    {
        weight[i] = I;
    }

    weight[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        int minIndex = minWeightIndex(weight, visited, V);

        visited[minIndex] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[minIndex][v] != I && !visited[v] && graph[minIndex][v] < weight[v])
            {
                parent[v] = minIndex;
                weight[v] = graph[minIndex][v];
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < V; i++)
    {
        sum += weight[i];
    }

    return sum;
}

int main()
{

    // 3 3
    // 0 1 5 1 2 3 0 2 1
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, I));
    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    cout << spanningTree(V, E, graph);
}