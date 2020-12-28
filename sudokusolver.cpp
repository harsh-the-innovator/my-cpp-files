#include <bits/stdc++.h>
using namespace std;
const int D = 9;

bool canPlace(int board[D][D], int n, int row, int col, int curNum)
{
    if (board[row][col] != 0)
        return false;

    // check row and col
    for (int x = 0; x < n; x++)
    {
        if (board[row][x] == curNum)
            return false; //row already contains that number
        if (board[x][col] == curNum)
            return false; //col already contains that number
    }

    // check for box
    int rootn = sqrt(n);
    int boxRow = row / rootn;
    int boxCol = col / rootn;

    int boxStartCellRow = boxRow * rootn;
    int boxStartCellCol = boxCol * rootn;
    for (int i = boxStartCellRow; i < boxStartCellRow + rootn; i++)
    {
        for (int j = boxStartCellCol; j < boxStartCellCol + rootn; j++)
        {
            if (board[i][j] == curNum)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int board[D][D], int n, int row, int col)
{
    if (row == n)
        return true;
    if (col == n)
    {
        return solveSudoku(board, n, row + 1, 0);
    }

    // check for fixed cell
    if (board[row][col] != 0)
        return solveSudoku(board, n, row, col + 1);

    for (int curNum = 1; curNum <= 9; curNum++)
    {
        if (canPlace(board, n, row, col, curNum) == true)
        {
            // if we can place then place the number
            board[row][col] = curNum;
            bool success = solveSudoku(board, n, row, col + 1);
            if (success == true)
                return true;
            board[row][col] = 0;
        }
    }

    // all numbers checked not solvable
    return false;
}

void printBoard(int board[D][D], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int board[D][D] = {{0, 1, 0, 0, 0, 0, 6, 0, 5},
                       {5, 0, 3, 0, 0, 0, 2, 7, 8},
                       {0, 4, 6, 0, 8, 2, 0, 0, 1},
                       {0, 3, 0, 0, 5, 9, 0, 0, 0},
                       {1, 5, 0, 0, 0, 0, 0, 3, 7},
                       {0, 0, 0, 1, 3, 0, 0, 5, 0},
                       {2, 0, 0, 9, 6, 0, 4, 1, 0},
                       {4, 8, 1, 0, 0, 0, 5, 0, 9},
                       {3, 0, 9, 0, 0, 0, 0, 8, 0}};

    // int n;
    // cin >> n;

    bool ans = solveSudoku(board, D, 0, 0);

    if (ans == true)
    {
        // function solved it
        printBoard(board, D);
    }
    else
    {
        cout << "Not solvable" << endl;
    }
}