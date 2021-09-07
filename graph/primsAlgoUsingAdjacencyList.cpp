#include <bits/stdc++.h>
using namespace std;

#define I INT_MAX
#define pi pair<int, int>

void spanningTree(vector<pi> graph[], int V)
{
    int parent[V][2]; //for storing parent as well as weight of edge i -> parent[i][0] in parent[i][1];
    int weight[V];
    bool mstSet[V]{false};

    for (int i = 0; i < V; i++)
    {
        weight[i] = I;
    }

    weight[0] = 0;
    parent[0][0] = -1;
    parent[0][1] = I;

    //weight will be first and vertex index will be second in pair
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({0, 0});

    while (!pq.empty())
    {
        // get minimum weight vertex
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto itr : graph[u])
        {
            int v = itr.first;
            int edge_wt = itr.second;

            if (!mstSet[v] && edge_wt < weight[v])
            {
                weight[v] = edge_wt;
                parent[v][0] = u;
                parent[v][1] = edge_wt;
                pq.push({weight[v], v});
            }
        }
    }
    int cost = 0;
    cout << "Minimum Spanning tree array:\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i][0] << " -> " << i << " = " << parent[i][1] << endl;
        cost += parent[i][1];
    }
    cout << "min cost = " << cost << endl;
}

void addWeightedEdge(vector<pi> graph[], int u, int v, int w)
{
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

int main()
{

    // 3 3
    // 0 1 5 1 2 3 0 2 1
    int V, E;
    cin >> V >> E;
    vector<pi> graph[V];
    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addWeightedEdge(graph, u, v, w);
    }
    spanningTree(graph, V);
}