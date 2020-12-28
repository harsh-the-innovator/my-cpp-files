#include <bits/stdc++.h>
using namespace std;
// example
// IP: a1B2
// OP: a1B2 a1b2 A1b2 A1B2

void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;

        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));

        ip.erase(ip.begin());
        solve(ip, op1);
        solve(ip, op2);
    }
    else
    {
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin());
        solve(ip, op1);
    }
}

int main()
{
    string str;
    cin >> str;
    solve(str, "");
}