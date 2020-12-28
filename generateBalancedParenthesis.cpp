// generate all balanced parenthesis
// given input n:- number of open and close brackets
#include <bits/stdc++.h>
using namespace std;

void solve(string op, int open, int close)
{
    if (open == 0 && close == 0)
    {
        cout << op << endl;
        return;
    }

    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        solve(op1, open - 1, close);
    }

    if (open < close)
    {
        string op2 = op;
        op2.push_back(')');
        solve(op2, open, close - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    int open = n;
    int close = n;

    solve("", open, close);
}