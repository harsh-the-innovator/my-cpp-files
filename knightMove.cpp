// backtracking
#include <bits/stdc++.h>
using namespace std;
const int D = 8;

bool canPlace(int board[D][D], int n, int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < n && board[r][c] == 0;
}

bool solveKnightMove(int board[D][D], int n, int move_no, int curRow, int curCol)
{
    if (move_no == n * n)
    {
        return true;
    }

    static int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    static int colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1};

    for (int curDir = 0; curDir < 8; ++curDir)
    {
        int nextRow = curRow + rowDir[curDir];
        int nextCol = curCol + colDir[curDir];

        if (canPlace(board, n, nextRow, nextCol) == true)
        {
            // place the knight
            board[nextRow][nextCol] = move_no + 1;
            bool isSuccessfull = solveKnightMove(board, n, move_no + 1, nextRow, nextCol);
            if (isSuccessfull)
                return true;
            // erase the knight if not successfull and see the next direction
            board[nextRow][nextCol] = 0;
        }
    }

    // all directions have been checked
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
    int board[D][D]{0};
    int n;
    cin >> n;

    board[0][0] = 1;
    bool ans = solveKnightMove(board, n, 1, 0, 0);

    if (ans)
    {
        // function solved it
        printBoard(board, n);
    }
    else
    {
        cout << "Not solvable" << endl;
    }
}