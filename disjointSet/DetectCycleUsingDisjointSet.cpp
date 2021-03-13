#include <bits/stdc++.h>
using namespace std;

//USING UNION-FIND

//FIND operation
int find(int v, vector<int> &parent)
{
    if (parent[v] == -1)
        return v;
    return find(parent[v], parent);
}

void union_op(int fromP, int toP, vector<int> &parent)
{
    fromP = find(fromP, parent);
    toP = find(toP, parent);
    parent[fromP] = toP;
}

bool isCyclic(vector<pair<int, int>> &edge_List, vector<int> &parent)
{
    for (auto p : edge_List)
    {
        int fromP = find(p.first, parent); //FIND absolute parent of subset
        int toP = find(p.second, parent);

        if (fromP == toP) //when both vertices belong to same set then there is cycle
            return true;

        //UNION operation
        union_op(fromP, toP, parent); //UNION of 2 sets
    }
    return false;
}

int main()
{
    int E; //No of edges
    int V; //No of vertices (0 to V-1)
    cin >> V >> E;
    vector<int> parent(V, -1); //Mark all vertices as separate subsets with only 1 element

    vector<pair<int, int>> edge_List; //Adjacency list
    for (int i = 0; i < E; ++i)
    {
        int from, to;
        cin >> from >> to;
        edge_List.push_back({from, to});
    }

    if (isCyclic(edge_List, parent))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";

    return 0;
}

//TIME COMPLEXITY: O(E.V)