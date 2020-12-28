#include <iostream>
#include <vector>
using namespace std;
void printSolution(int color[], int V)
{
    cout << "\nAssigned colors:\n";
    for (int i = 0; i < V; i++)
    {
        cout << color[i] << " ";
    }
    cout << endl;
}
bool isSafe(vector<int> graph[], int color[], int c, int i, int V)
{
    for (auto itr = graph[i].begin(); itr != graph[i].end(); itr++)
    {
        if (c == color[*itr])
            return false;
    }

    return true;
}
bool graphColoring(vector<int> graph[], int m, int color[], int i, int V)
{
    if (i == V) //all vertices are done
        return true;

    //assignment of color to vertex i
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(graph, color, c, i, V))
        {
            color[i] = c;

            if (graphColoring(graph, m, color, i + 1, V) == true)
            {
                return true;
            }

            color[i] = 0;
        }
    }

    return false;
}
void solve(vector<int> graph[], int m, int V)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    //starting from vertex 0
    if (graphColoring(graph, m, color, 0, V) == false)
    {
        cout << "Solution doesn't exist";
    }
    else
    {
        printSolution(color, V);
    }
}
int main()
{
    // bool graph[V][V] = {  0 ,1 ,2 ,3
    //                     0{0, 1, 1, 1},
    //                     1{1, 0, 1, 0},
    //                     2{1, 1, 0, 1},
    //                     3{1, 0, 1, 0}};
    int V, m;
    int s, d; //source destination edge in undirected graph
    int e;    //edges
    cout << "Enter number of vertices:\n";
    cin >> V;
    cout << "Enter number of edges:\n";
    cin >> e;
    vector<int> graph[V];
    cout << "Enter vertices pair of connected edges:\n";
    for (int i = 0; i < e; i++)
    {
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    cout << "Enter m:\n";
    cin >> m;

    solve(graph, m, V);
    return 0;
}