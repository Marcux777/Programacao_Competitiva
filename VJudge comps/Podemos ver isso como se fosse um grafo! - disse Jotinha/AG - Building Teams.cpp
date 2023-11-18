#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, vector<vector<int>> &graph, vector<int> &color)
{
    for (auto v : graph[u])
    {
        if (!color[v])
        {
            color[v] = (color[u] == 2) ? 1 : 2;
            if (!dfs(v, graph, color))
            {
                return false;
            }
        }
        else
        {
            if (color[u] == color[v])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            color[i] = 1;
            if (!dfs(i, graph, color))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
    }
    cout << endl;
}