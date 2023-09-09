#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> adj;

void dfs(int v, vector<bool> &visited, set<int> &component, int &edgeCount)
{
    visited[v] = true;
    component.insert(v);
    edgeCount++;

    for (auto u : adj[v])
    {
        if (!visited[u])
        {
            dfs(u, visited, component, edgeCount);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);
    bool goodParty = false;

    for (int i = 1; i <= n && !goodParty; i++)
    {
        if (!visited[i])
        {
            int edgeCount = 0;
            set<int> component;
            dfs(i, visited, component, edgeCount);
            cout << edgeCount << endl
                 << component.size() << endl;
            if (edgeCount >= 3 || edgeCount == 0)
            {
                goodParty = true;
            }
        }
    }

    if (goodParty)
    {
        cout << "Festa bunita, festa formosa." << endl;
    }
    else
    {
        cout << "Role torto." << endl;
    }

    return 0;
}
