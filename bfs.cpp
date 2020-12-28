#include <iostream>
#include <list>
#include <iterator>
using namespace std;
const int v = 6;
void BFS(int adj[][v + 1], int startIndex)
{
    list<int> queue;
    int visited[v + 1] = {0};

    visited[startIndex] = 1;
    list<int>::iterator itr;
    queue.push_back(startIndex);

    while (!queue.empty())
    {
        int s;
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (int i = 1; i <= v; i++)
        {
            if (adj[s][i] && !visited[i])
            {
                queue.push_back(i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    // initializing visited array
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
    BFS(adj, start);
}