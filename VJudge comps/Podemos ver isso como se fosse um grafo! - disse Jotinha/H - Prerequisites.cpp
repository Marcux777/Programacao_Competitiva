#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &result)
{
    vis[u] = true;

    for (auto v : graph[u])
    {
        if (!vis[v])
        {
            dfs(v, graph, vis, result);
        }
    }
    result.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int livro;
            cin >> livro;
            graph[i].push_back(livro);
        }
    }
    vector<int> result;
    dfs(1, graph, vis, result);
    for (auto i : result)
    {
        if (i != 1)
        {
            cout << i << " ";
        }
    }
}