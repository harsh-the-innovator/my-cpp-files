#include <bits/stdc++.h>
using namespace std;
// exanple:
// IP: "ab"
// OP: ab aB Ab AB

void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));

    ip.erase(ip.begin());

    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    string str; //for lower string only
    cin >> str;
    solve(str, "");
}