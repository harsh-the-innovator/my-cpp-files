// codechef june cook off div2
#include <bits/stdc++.h>
using namespace std;
#define ld long double

void dfs(vector<int> *graph, int sv, int mark[], vector<int> &temp, int visited[])
{
    visited[sv] = 1;

    for (int i = 0; i < graph[sv].size(); i++)
    {
        if (visited[graph[sv][i]] == 0 && mark[graph[sv][i]] == 1)
        {

            temp.push_back(graph[sv][i]);
            dfs(graph, graph[sv][i], mark, temp, visited);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        ld income[n];
        ld population[n];
        int mark[n]{0};
        for (int i = 0; i < n; i++)
        {
            cin >> income[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> population[i];
        }

        ld maxInc = 0;
        for (int i = 0; i < n; i++)
        {
            ld t;
            t = income[i] / population[i];
            maxInc = max(t, maxInc);
        }

        vector<int> maxNodes;
        for (int i = 0; i < n; i++)
        {
            if (income[i] / population[i] == maxInc)
            {
                mark[i] = 1;
                maxNodes.push_back(i);
            }
        }

        vector<int> *graph = new vector<int>[m];
        for (int i = 0; i < m; i++)
        {
            int j, k;
            cin >> j >> k;
            graph[j - 1].push_back(k - 1);
            graph[k - 1].push_back(j - 1);
        }

        std::vector<int> final;
        int visited[n]{0};

        for (int i = 0; i < maxNodes.size(); i++)
        {

            vector<int> temp;
            temp.push_back(maxNodes[i]);
            if (visited[maxNodes[i]] == 0)
                dfs(graph, maxNodes[i], mark, temp, visited);

            if (temp.size() > final.size())
            {
                final = temp;
            }
            temp.clear();
        }

        cout << final.size() << endl;
        for (int i = 0; i < final.size(); i++)
        {
            cout << final[i] + 1 << " ";
        }
    }
}