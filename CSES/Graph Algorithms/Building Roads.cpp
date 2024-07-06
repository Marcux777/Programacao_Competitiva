#include <bits/stdc++.h>
 
using namespace std;
 
void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : graph[u])
    {
        if (!vis[v])
        {
            dfs(v, graph, vis);
        }
    }
    u;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> roads;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            roads.push_back(i);
            dfs(i, graph, vis);
        }
    }
    cout << roads.size() - 1 << endl;
    for (int i = 0; i < roads.size() - 1; i++)
    {
        cout << roads[i] << " " << roads[i + 1] << endl;
    }
}