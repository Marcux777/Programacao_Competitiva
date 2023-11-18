#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define INF LLONG_MAX

void printPath(vector<int> &parent, int j)
{
    if (parent[j] == -1)
    {
        cout << j << " ";
        return;
    }
    printPath(parent, parent[j]);

    cout << j << " ";
}

void dijkstra(vector<vector<pair<int, int>>> &graph, int start, int end)
{
    int n = graph.size();
    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    parent[start] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});

    while (!queue.empty())
    {
        int current_node = queue.top().second;
        queue.pop();

        for (auto edge : graph[current_node])
        {
            int adj_node = edge.first;
            int weight = edge.second;

            if (dist[current_node] + weight < dist[adj_node])
            {
                dist[adj_node] = dist[current_node] + weight;
                parent[adj_node] = current_node;
                queue.push({dist[adj_node], adj_node});
            }
        }
    }

    if (parent[end] == -1)
        cout << -1 << endl;
    else
        printPath(parent, end);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }
    dijkstra(graph, 1, n);
}