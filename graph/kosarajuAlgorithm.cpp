// A directed graph is strongly connected if there is a path between all pairs of vertices.
//  A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
// TIME COMPLEXITY = O(V+E)
#include <bits/stdc++.h>
using namespace std;

void fillOrder(vector<int> graph[], int src, vector<bool> &visited, stack<int> &st)
{
    visited[src] = true;

    for (auto v : graph[src])
    {
        if (!visited[v])
        {
            fillOrder(graph, v, visited, st);
        }
    }

    st.push(src);
}

void transposeGraph(vector<int> graph[], vector<int> reversedGraph[], int V)
{
    for (int u = 0; u < V; u++)
    {
        for (auto v : graph[u])
        {
            reversedGraph[v].push_back(u);
        }
    }
}

void dfsForPrinting(vector<int> reversedGraph[], int src, vector<bool> &visited)
{
    visited[src] = true;

    cout << src << " ";

    for (auto v : reversedGraph[src])
    {
        if (!visited[v])
        {
            dfsForPrinting(reversedGraph, v, visited);
        }
    }
}

void kosarajuAlgo(vector<int> graph[], int V)
{
    stack<int> st;

    // Mark all the vertices as not visited (For first DFS)
    vector<bool> visited(V, false);

    // Fill vertices in stack according to their finishing times
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            fillOrder(graph, i, visited, st);
    }

    //Create a reversed graph
    vector<int> reversedGraph[V];
    transposeGraph(graph, reversedGraph, V);

    // Mark all the vertices as not visited (For second DFS)
    for (auto el : visited)
    {
        el = false;
    }

    // Now process all vertices in order defined by Stack
    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (visited[u] == false)
        {
            dfsForPrinting(reversedGraph, u, visited);
            cout << endl;
        }
    }
}

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
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

    kosarajuAlgo(graph, V);
}