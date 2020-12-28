#include <iostream>
#include <climits>
using namespace std;
#define I 10000
int findMin(int dist[], bool visited[])
{

    int min = I;
    int u;

    for (int i = 1; i <= 5; i++)
    {
        if (dist[i] < min && !visited[i])
        {
            min = dist[i];
            u = i;
        }
    }

    return u;
}
void dijstraAlgo(int cost[][6], int s)
{
    int dist[6];
    bool visited[6];

    for (int i = 1; i <= 5; i++)
    {
        dist[i] = I;
        visited[i] = false;
    }
    dist[s] = 0;

    for (int i = 1; i <= 4; i++)
    {
        int u = findMin(dist, visited);
        visited[u] = true;

        for (int v = 1; v <= 5; v++)
        {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v] && dist[u] != I)
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int cost[6][6] = {{I, I, I, I, I, I},
                      {I, I, 4, 1, I, I},
                      {I, I, I, I, I, 4},
                      {I, I, 2, I, 4, I},
                      {I, I, I, I, I, 4},
                      {I, I, I, I, I, I}};
    int start = 1;

    dijstraAlgo(cost, start);

    return 0;
}