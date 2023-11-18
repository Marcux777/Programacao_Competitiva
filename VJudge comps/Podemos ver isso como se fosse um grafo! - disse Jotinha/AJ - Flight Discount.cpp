#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define INF LLONG_MAX

void dijkstra(vector<vector<pair<int, int>>> &graph, int start, int end)
{
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(2, INF));

    dist[start][0] = 0LL;
    // um par que contém o custo total para chegar ao nó e um par que contém o nó atual e um indicador se o cupom foi usado ou não.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> queue;
    queue.push({0, {1, 0}}); // cupom não usado

    while (!queue.empty())
    {
        int w = queue.top().first;
        int current_node = queue.top().second.first;
        int u = queue.top().second.second;
        queue.pop();

        if (w > dist[current_node][u])
            continue;

        for (auto edge : graph[current_node])
        {
            int adj_node = edge.first;
            int weight = w + edge.second;

            if (weight < dist[adj_node][u])
            {
                dist[adj_node][u] = weight;
                queue.push({weight, {adj_node, u}});
            }
            if (!u)
            {
                weight = w + edge.second / 2;
                if (weight < dist[adj_node][1])
                {
                    dist[adj_node][1] = weight;
                    queue.push({weight, {adj_node, 1}});
                }
            }
        }
    }
    cout << min(dist[end][0], dist[end][1]) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        // graph[y].push_back({x, w});
    }
    dijkstra(graph, 1, n);
}