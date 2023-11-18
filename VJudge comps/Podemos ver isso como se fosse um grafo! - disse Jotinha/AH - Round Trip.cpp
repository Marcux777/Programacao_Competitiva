#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define INF LLONG_MAX

int dijsktra(int start, int end, vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});

    while (!queue.empty())
    {
        int u = queue.top().second;
        queue.pop();
        if (visited[u])
            continue;

        visited[u] = true;
        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                queue.push({dist[v], v});
            }
            if (dist[u] + w / 2 < dist[v])
            {
                dist[v] = dist[u] + w / 2;
                queue.push({dist[v], v});
            }
        }
    }
    return dist[end];
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b, w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    cout << dijsktra(1, n, graph) << endl;
}