#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dst, wt;
    Edge(int u, int v, int w)
    {
        src = u;
        dst = v;
        wt = w;
    }
};

bool compare(Edge &e1, Edge &e2)
{
    return e1.wt < e2.wt;
}

// UNION BY RANK AND PATH COMPRESSION CODE:-
int find(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v], parent); // path compression
}
void union_op(int fromP, int toP, vector<int> &parent, vector<int> &rank)
{
    // UNION by RANK

    if (rank[fromP] > rank[toP]) // fromP has higher rank
    {
        parent[toP] = fromP;
    }
    else if (rank[fromP] < rank[toP]) // toP has higher rank
    {
        parent[fromP] = toP;
    }
    else
    {
        // Both have same rank and so anyone can be made as parent
        parent[fromP] = toP;
        rank[toP]++; // Increase rank of parent
    }
}

// KRUSKAL ALGO
int kruskalAlgo(vector<Edge> &edgesList, int V, int E)
{
    // sorting edges on the basis of their weights in ascending
    sort(edgesList.begin(), edgesList.end(), compare);

    // parent and rank array for disjoint set
    vector<int> parent(V);
    vector<int> rank(V);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    // minimum cost
    int res = 0;

    // main algo of kruskal
    // s is the size of MST
    for (int i = 0, s = 0; i < E && s < V - 1; i++)
    {
        Edge e = edgesList[i];

        int x = find(e.src, parent);
        int y = find(e.dst, parent);

        if (x != y)
        {
            res += e.wt;
            union_op(x, y, parent, rank);
            s++;
        }
    }

    return res;
}

int main()
{
    int V, E, u, v, w;
    cin >> V >> E;
    vector<Edge> edgesList;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        edgesList.push_back({u, v, w});
    }

    cout << endl;

    for (auto el : edgesList)
    {
        cout << el.src << " " << el.dst << " " << el.wt << endl;
    }

    cout << "Minimum cost spanning tree = ";
    cout << kruskalAlgo(edgesList, V, E);
}
// 3 3
// 0 1 5 1 2 3 0 2 1