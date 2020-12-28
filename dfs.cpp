#include <iostream>
using namespace std;
const int v = 6;

void DFS(int adj[][v + 1], int startIndex)
{
    static int visited[7] = {0};

    if (visited[startIndex] == 0)
    {
        cout << startIndex << " ";
        visited[startIndex] = 1;
        for (int j = 1; j <= v; j++)
        {
            if (adj[startIndex][j] == 1 && !visited[j])
            {
                DFS(adj, j);
            }
        }
    }
}

int main()
{
    int start;
    int adj[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 0, 0, 0},
                     {0, 1, 0, 0, 1, 0, 0},
                     {0, 1, 0, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};
    cout << "Enter starting index: ";

    cin >> start;
    DFS(adj, start);
}