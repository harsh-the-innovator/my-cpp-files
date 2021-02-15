#include <bits/stdc++.h>
using namespace std;

void printAll(int b[2][3])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << &b[i][j] << " ";
        }
    }

    cout << endl;
}

int main()
{

    int b[2][3] = {{2, 3, 6}, {4, 5, 8}};

    printAll(b);

    cout << b << endl;
    cout << &b[0] << endl;
    cout << *b << endl;
    cout << b[0] << endl;
    cout << &b[0][0] << endl;
}