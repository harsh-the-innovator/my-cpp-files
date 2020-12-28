// codechef july 2020 long challenge div 2
#include <bits/stdc++.h>
using namespace std;
#define N 8
char board[N + 1][N + 1];

bool isSafe(int r, int c)
{
    if (r >= 1 && r <= N && c >= 1 && c <= N)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(board, '.', sizeof(board));
        int k;
        cin >> k;
        int row;
        int col;

        for (int x = 1; x <= k; x++)
        {
            row = ceil(x / 8.0);
            col = x % 8 == 0 ? 8 : x % 8;
            board[row][col] = '.';
            if (isSafe(row + 1, col))
            {
                board[row + 1][col] = 'X';
            }
            if (isSafe(row + 1, col + 1))
            {
                board[row + 1][col + 1] = 'X';
            }
            if (isSafe(row, col + 1))
            {
                board[row][col + 1] = 'X';
            }
        }

        board[1][1] = 'O';

        // print solution
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
}