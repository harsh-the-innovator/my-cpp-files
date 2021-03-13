//topological sort using BFS(only for DAG)

#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> graph[], int V, int indegree[])
{
    queue<int> q;

    //putting all 0 indegree vertices in queue
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";
        for (auto v : graph[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

void addEdge(vector<int> graph[], int u, int v, int indegree[])
{
    graph[u].push_back(v);
    indegree[v]++;
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
    int indegree[V]{0}; //creating indegree array to contain indegree of all vertices

    cout << "Now enter edge vertices in space seperated like: u to v\n";
    for (int i = 1; i <= E; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v, indegree);
    }

    cout << "\nTopological Sort:\n";
    topologicalSort(graph, V, indegree);
}