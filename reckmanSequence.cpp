#include <bits/stdc++.h>
using namespace std;
void printSeq(vector<int> &v, unordered_set<int> &s, int n)
{
    if (n == 0)
    {
        cout << "0 ";
        v.push_back(0);
        s.insert(0);
        return;
    }

    printSeq(v, s, n - 1);
    if (v[n - 1] - n > 0 && s.find(v[n - 1] - n) == s.end())
    {
        cout << v[n - 1] - n << " ";
        v.push_back(v[n - 1] - n);
        s.insert(v[n - 1] - n);
    }
    else
    {
        cout << v[n - 1] + n << " ";
        v.push_back(v[n - 1] + n);
        s.insert(v[n - 1] + n);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_set<int> s;
        vector<int> v;
        printSeq(v, s, n - 1);
        cout << endl;
    }
}