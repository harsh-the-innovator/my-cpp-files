#include <iostream>
using namespace std;
//see gfg for detail
// in this q we have to find the no of pallindromic substrings  of length min 2 in given string
bool isPal(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }

    return true;
}

int countSubstrings(string s, int i, int j)
{
    if (j == i + 1)
        return s[i] == s[j];

    if (i == j || i > j)
        return 0;

    if (isPal(s, i, j) == true)
    {
        return 1 + countSubstrings(s, i, j - 1) + countSubstrings(s, i + 1, j) - countSubstrings(s, i + 1, j - 1);
    }
    else
    {
        return countSubstrings(s, i, j - 1) + countSubstrings(s, i + 1, j) - countSubstrings(s, i + 1, j - 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        cout << countSubstrings(s, 0, n - 1) << endl;
    }
    return 0;
}

//take example abaab ans = 3;
//take example abbaeae ans = 4;