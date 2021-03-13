//topological sort using DFS(only for DAG)

#include <bits/stdc++.h>
using namespace std;

void graphDFS(vector<int> graph[], int src, bool visited[], stack<int> &st)
{
    visited[src] = true;

    for (auto v : graph[src])
    {
        if (!visited[v])
        {
            graphDFS(graph, v, visited, st);
        }
    }

    st.push(src);
}

void topologicalSort(vector<int> graph[], int V)
{
    bool visited[V]{false};
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            graphDFS(graph, i, visited, st);
        }
    }

    // printing topological sort order
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

int main()
{
    int V, E, u, v;
    cout << "Enter no of vertices:";
    cin >> V;
    cout << "Enter no .of edges:";
    cin >> E;

    //array of vectors as adjacency list
    vector<int> graph[V];

    cout << "Now enter edge vertices in space seperated like: u to v\n";
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    cout << "\nTopological Sort:\n";
    topologicalSort(graph, V);
}