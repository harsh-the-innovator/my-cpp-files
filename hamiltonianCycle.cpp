#include <bits/stdc++.h>
using namespace std;
const int V = 5;

bool isSafe(bool graph[V][V], int path[], int pos, int v)
{
    // Check if this vertex is an adjacent vertex of the previously added vertex.

    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included.
    for (int i = 0; i < V; i++)
    {
        if (path[i] == v)
        {
            return false;
        }
    }

    return true;
}

bool hamiltonianCycle(bool graph[V][V], int path[], int pos) //pos is the index of elements in path
{
    //base case
    if (pos == V)
    {

        // check if there is an edge from last included vertex to vertex 0
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // now check for different vertices
    for (int v = 1; v < V; v++)
    {

        // check if vertex v can be added to cycle
        if (isSafe(graph, path, pos, v))
        {
            path[pos] = v;

            bool success = hamiltonianCycle(graph, path, pos + 1);
            if (success)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

void printSol(int path[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << path[i] << " ";
    }
    cout << path[0] << " " << endl;
}

void solve(bool graph[V][V])
{

    int path[V];
    memset(path, -1, sizeof(path));

    path[0] = 0; //start from 0
    //put the value of vertex in path[0] to start
    // ex. path[0] = 2 - start from vertex 2

    if (hamiltonianCycle(graph, path, 1))
    {
        printSol(path, V);
    }
    else
    {
        cout << "Solution doesn't exist";
    }
}

int main()
{
    bool graph[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};

    solve(graph);
}