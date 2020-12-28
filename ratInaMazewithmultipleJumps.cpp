#include <bits/stdc++.h>
using namespace std;
#define N 4

void printSol(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int i, int j)
{
    return (i >= 0 && j >= 0 && i < N && j < N && maze[i][j] != 0);
}

bool solveMazeUtil(int maze[N][N], int path[N][N], int i, int j)
{
    if (i == N - 1 && j == N - 1)
    {
        path[i][j] = 1;
        return true;
    }

    if (isSafe(maze, i, j))
    {
        path[i][j] = 1;
        int maxValue = maze[i][j];
        for (int k = 1; k <= maxValue && k < N; k++)
        {
            if (solveMazeUtil(maze, path, i, j + k))
                return true;

            if (solveMazeUtil(maze, path, i + k, j))
                return true;
        }

        path[i][j] = 0;
    }

    return false;
}

void solveMaze(int maze[N][N])
{
    int path[N][N]{{0}};

    if (solveMazeUtil(maze, path, 0, 0))
    {
        printSol(path);
    }
    else
    {
        cout << "Solution does not exist" << endl;
    }
}

int main()
{
    int maze[N][N] = {{2, 1, 0, 0},
                      {3, 0, 0, 1},
                      {0, 1, 0, 1},
                      {0, 0, 0, 1}};
    solveMaze(maze);
}