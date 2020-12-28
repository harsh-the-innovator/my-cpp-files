#include <bits/stdc++.h>
using namespace std;
const int N = 4;

void printSol(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << "\t";
        }
        cout << endl;
    }
}

bool canPlace(int maze[N][N], int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int i, int j, int sol[N][N])
{
    if (i == N - 1 && j == N - 1 && maze[i][j] == 1)
    {
        sol[i][j] = 1;
        return true;
    }

    if (canPlace(maze, i, j))
    {
        sol[i][j] = 1;

        if (solveMaze(maze, i, j + 1, sol))
            return true;

        if (solveMaze(maze, i + 1, j, sol))
            return true;

        sol[i][j] = 0;

        return false;
    }

    return false;
}

void solve(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (solveMaze(maze, 0, 0, sol))
    {
        printSol(sol);
    }
    else
    {
        cout << "No solution" << endl;
    }
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};
    solve(maze);
}