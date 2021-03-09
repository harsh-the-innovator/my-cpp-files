#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<int> graph[], int V)
{
    for (int u = 0; u < V; u++)
    {
        for (auto v : graph[u])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter no of vertices:";
    cin >> V;
    cout << "Enter no .of edges:";
    cin >> E;

    //array of vectors as adjacency list
    vector<int> graph[V];

    int u, v;
    cout << "Now enter edge vertices in space seperated like: u v\n";
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    cout << "\nPrinting graph:\n";
    printGraph(graph, V);

    return 0;
}