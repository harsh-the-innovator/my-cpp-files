#include <bits/stdc++.h>
using namespace std;

// USING UNION BY RANK AND PATH COMPRESSION

//FIND operation
int find(int v, vector<int> &parent)
{
    if (parent[v] == -1)
        return v;
    return parent[v] = find(parent[v], parent); //path compression
}

void union_op(int fromP, int toP, vector<int> &parent, vector<int> &rank)
{
    //UNION by RANK

    if (rank[fromP] > rank[toP]) //fromP has higher rank
    {
        parent[toP] = fromP;
    }
    else if (rank[fromP] < rank[toP]) //toP has higher rank
    {
        parent[fromP] = toP;
    }
    else
    {
        //Both have same rank and so anyone can be made as parent
        parent[fromP] = toP;
        rank[toP]++; //Increase rank of parent
    }
}

bool isCyclic(vector<pair<int, int>> &edge_List, vector<int> &parent, vector<int> &rank)
{
    for (auto p : edge_List)
    {
        int fromP = find(p.first, parent); //FIND absolute parent of subset
        int toP = find(p.second, parent);

        if (fromP == toP) //when both vertices belong to same set then there is cycle
            return true;

        //UNION operation
        union_op(fromP, toP, parent, rank); //UNION of 2 sets
    }
    return false;
}

int main()
{
    int E; //No of edges
    int V; //No of vertices (0 to V-1)
    cin >> V >> E;
    vector<int> parent(V, -1); //Mark all vertices as separate subsets with only 1 element
    vector<int> rank(V, 0);

    vector<pair<int, int>> edge_List; //Adjacency list
    for (int i = 0; i < E; ++i)
    {
        int from, to;
        cin >> from >> to;
        edge_List.push_back({from, to});
    }

    if (isCyclic(edge_List, parent, rank))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";

    return 0;
}

//TIME COMPLEXITY: O(E.V)