#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, char> keymap;

    keymap['W'] = 'Q';
    keymap['E'] = 'W';
    keymap['R'] = 'E';
    keymap['T'] = 'R';
    keymap['Y'] = 'T';
    keymap['U'] = 'Y';
    keymap['I'] = 'U';
    keymap['O'] = 'I';
    keymap['P'] = 'O';
    keymap['['] = 'P';
    keymap['S'] = 'A';
    keymap['D'] = 'S';
    keymap['F'] = 'D';
    keymap['G'] = 'F';
    keymap['H'] = 'G';
    keymap['J'] = 'H';
    keymap['K'] = 'J';
    keymap['L'] = 'K';
    keymap[';'] = 'L';
    keymap['\''] = ';';
    keymap['X'] = 'Z';
    keymap['C'] = 'X';
    keymap['V'] = 'C';
    keymap['B'] = 'V';
    keymap['N'] = 'B';
    keymap['M'] = 'N';
    keymap[','] = 'M';
    keymap['.'] = ',';
    keymap['/'] = '.';
    keymap[' '] = ' ';

    char a;
    map<char, char>::iterator itr;
    while (cin >> a)
    {
        if (a == 'n')
        {
            break;
        }

        itr = keymap.find(a);
        if (itr == keymap.end())
            cout << a;
        else
            cout << itr->second;
    }
    cout << endl;

    return 0;
}