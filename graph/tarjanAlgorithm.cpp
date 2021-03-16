//tarjan algorithm for strongly connected components (SCC)
// TIME COMPLEXITY = O(V+E)
#include <bits/stdc++.h>
using namespace std;

void findSCCUtil(int u, vector<int> graph[], vector<int> &disc, vector<int> &low, vector<bool> &inStack, stack<int> &st)
{
    static int timer = 0;
    disc[u] = low[u] = ++timer;

    st.push(u);
    inStack[u] = true;

    for (auto v : graph[u])
    {
        // If v is not visited yet, then recur for it
        if (disc[v] == -1)
        {
            findSCCUtil(v, graph, disc, low, inStack, st);

            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v] == true)
        {
            // Update low value of 'u' only of 'v' is still in stack
            // (i.e. it's a back edge, not cross edge).
            low[u] = min(low[u], disc[v]);
        }
    }

    // head node found, pop the stack and print an SCC
    int x = 0;
    if (low[u] == disc[u])
    {
        while (st.top() != u)
        {
            x = st.top();
            cout << x << " ";
            inStack[x] = false;
            st.pop();
        }

        x = st.top();
        cout << x << endl;
        inStack[x] = false;
        st.pop();
    }
}

void findSCC(vector<int> graph[], int V)
{
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
        {
            findSCCUtil(i, graph, disc, low, inStack, st);
        }
    }
}

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

int main()
{
    int V, E, u, v;
    cin >> V >> E;

    vector<int> graph[V];
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    cout << "\nStrongly connected components:\n";
    findSCC(graph, V);
}