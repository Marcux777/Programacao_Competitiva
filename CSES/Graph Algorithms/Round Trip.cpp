#include <bits/stdc++.h>

using namespace std;

// https://cp-algorithms.com/graph/finding-cycle.html

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par)
{ // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : adj[v])
    {
        if (u == par)
            continue; // skipping edge to parent vertex
        if (visited[u])
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle()
{
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        cout << cycle.size() << endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    int m;
    cin >> n >> m;
    n++;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    find_cycle();
}