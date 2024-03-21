#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &vis, int u)
{
    if (vis[u])
        return;

    vis[u] = true;
    for (auto v : graph[u])
    {
        if (!vis[v])
        {
            dfs(graph, vis, v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(graph, vis, i);
            c++;
        }
    }
    cout << c << endl;
}