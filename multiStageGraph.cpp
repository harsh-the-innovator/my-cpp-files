// multi stage graph dp
#include <bits/stdc++.h>
using namespace std;
#define N 8
#define I INT_MAX
// Returns shortest distance from 0 to
// N-1.
int shortestDistance(int graph[N][N])
{
    // dist[i] is going to store shortest
    // distance from node i to node N-1.
    int dist[N];

    dist[N - 1] = 0;

    // Calculating shortest path for
    // rest of the nodes
    for (int i = N - 2; i >= 0; i--)
    {
        // Initialize distance from i to
        // destination (N-1)
        dist[i] = I;

        // Check all nodes of next stages
        // to find shortest distance from
        // i to N-1.
        for (int j = i; j < N; j++)
        {
            // if edges exists
            if (graph[i][j] != I)
            {
                dist[i] = min(dist[i], graph[i][j] + dist[j]);
            }
        }
    }

    return dist[0];
}

int main()
{
    int graph[N][N] =
        {{I, 1, 2, 5, I, I, I, I},
         {I, I, I, I, 4, 11, I, I},
         {I, I, I, I, 9, 5, 16, I},
         {I, I, I, I, I, I, 2, I},
         {I, I, I, I, I, I, I, 18},
         {I, I, I, I, I, I, I, 13},
         {I, I, I, I, I, I, I, 2}};

    cout << shortestDistance(graph) << endl;
}