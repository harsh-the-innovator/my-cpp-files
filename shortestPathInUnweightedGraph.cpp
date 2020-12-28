#include <iostream>
#include <list>
using namespace std;
void shortestPath(int G[][5], int startIndex)
{
    list<int> queue;
    int v;
    int distance[5];
    int path[5];
    queue.push_back(startIndex);
    for (int i = 1; i <= 4; i++)
    {
        distance[i] = -1;
    }
    distance[startIndex] = 0;

    while (!queue.empty())
    {
        v = queue.front();
        queue.pop_front();
        for (int i = 1; i <= 4; i++)
        {
            if (G[v][i] == 1) //condition of adjacent edges
            {
                if (distance[i] == -1) //distance is not assigned
                {
                    distance[i] = distance[v] + 1;
                    path[i] = v; //vertex from which we get the shortest distance
                    queue.push_back(i);
                }
            }
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 4; i++)
    {
        cout << path[i] << " ";
    }
}

int main()
{
    int adj[5][5] = {{0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 0},
                     {0, 0, 0, 1, 0},
                     {0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 0}};

    shortestPath(adj, 2);
    return 0;
}