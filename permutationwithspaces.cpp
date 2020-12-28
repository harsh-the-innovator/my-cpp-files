#include <bits/stdc++.h>
using namespace std;

void generatePermutations(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(' ');
    op1.push_back(ip[0]);

    op2.push_back(ip[0]);

    ip.erase(ip.begin());

    generatePermutations(ip, op1);
    generatePermutations(ip, op2);
}
int main()
{
    string str;
    cin >> str;
    string op = "";
    op.push_back(str[0]);
    str.erase(str.begin());
    generatePermutations(str, op);
}