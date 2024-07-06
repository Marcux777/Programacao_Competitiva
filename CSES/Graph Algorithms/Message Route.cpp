#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> bfs(vector<vector<int>> &graph, int start, int end)
{
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
 
    q.push(start);
    visited[start] = true;
 
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
 
        if (node == end)
        {
            vector<int> path;
            while (node != start)
            {
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }
 
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = node;
            }
        }
    }
 
    return {};
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("saida.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> result = bfs(graph, 1, n);
    int tam = result.size();
    (tam == 0) ? cout << "IMPOSSIBLE\n" : cout << tam << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << result[i];
        (i == tam - 1) ? cout << endl : cout << " ";
    }
}