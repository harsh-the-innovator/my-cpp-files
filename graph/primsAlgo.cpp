//Prims algorithm using adjacency matrix
//Time complexity = O(V^2);
#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX
int minWeightIndex(int weight[], bool mstSet[], int V)
{
    int min = I, minIndex;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && weight[v] < min)
            min = weight[v], minIndex = v;

    return minIndex;
}
int spanningTree(int V, vector<vector<int>> &graph)
{

    bool mstSet[V]{false}; //this will tell the vertices included in mstSet
    int parent[V];         //this array is just for printing MST
    int weight[V];         //this will tell the nodes weight

    for (int i = 0; i < V; i++)
    {
        weight[i] = I;
    }

    weight[0] = 0;
    parent[0] = -1;

    //loop for V-1 edges
    for (int i = 0; i < V - 1; i++)
    {
        int u = minWeightIndex(weight, mstSet, V);

        mstSet[u] = true;

        //looping for every adjacent vertex of u
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }

    int sum = 0;
    cout << "Minimum Spanning tree array:\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " -> " << i << " = " << graph[parent[i]][i] << endl;
        sum += graph[parent[i]][i];
    }
    cout << "Minimum cost = ";
    return sum;
}

void addWeightedEdge(vector<vector<int>> &graph, int u, int v, int w)
{
    graph[u][v] = w;
    graph[v][u] = w;
}

int main()
{

    // 3 3
    // 0 1 5 1 2 3 0 2 1
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addWeightedEdge(graph, u, v, w);
    }

    cout << spanningTree(V, graph);
}