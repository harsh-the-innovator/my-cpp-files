#include <bits/stdc++.h>
using namespace std;

void printGraph(int **graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void addEdge(int **graph, int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main()
{
    int V, E;
    cout << "Enter no of vertices:";
    cin >> V;
    cout << "Enter no .of edges:";
    cin >> E;

    //allocating memory
    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
    }

    //assigning value 0 to all intially
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }

    int u, v;
    cout << "Now enter edge vertices in space seperated like: u v\n";
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    cout << "\nPrinting graph:\n";
    printGraph(graph, V);

    //deallocating memory
    for (int i = 0; i < V; i++)
        delete[] graph[i];
    delete[] graph;
    return 0;
}