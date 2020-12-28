// given a chess board of n*n ,find all ways to place n queens such that they don't attack each other
// generating all possible solutions
#include <bits/stdc++.h>
using namespace std;

void printSol(int sol[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
}

bool canPlace(int sol[], int row, int col)
{

    // we have to check in very row less than current row that a current queen cannot be attacked
    // by any other row queen
    for (int i = 1; i <= row - 1; i++)
    {
        if ((sol[i] == col) || abs(i - row) == abs(sol[i] - col))
        {
            return false;
        }
    }

    return true;
}

void nQueens(int sol[], int n, int queenNo)
{

    if (queenNo > n)
    {
        printSol(sol, n);
        return;
    }

    // iterating through column in a row number(queenNo)
    for (int col = 1; col <= n; col++)
    {

        if (canPlace(sol, queenNo, col))
        {
            sol[queenNo] = col; //placing queen at row number = queenNo and at column number = col
            nQueens(sol, n, queenNo + 1);
            sol[queenNo] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int sol[n + 1]{0};

    nQueens(sol, n, 1);
}