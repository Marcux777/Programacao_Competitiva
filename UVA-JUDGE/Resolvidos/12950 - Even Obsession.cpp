#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

void dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end)
{
    int n = graph.size();
    vector<int> dist(n << 1, INF);
    dist[start << 1] = 0;
    priority_queue<pair<int, int>> queue;
    queue.push({0, start << 1});

    while (!queue.empty())
    {
        int d = -queue.top().first;
        int current_node = queue.top().second;
        queue.pop();
        int p = current_node & 1;
        current_node >>= 1;
        if ((current_node == end) && !p)
            break;
        p = 1 - p;

        for (auto edge : graph[current_node])
        {
            int adj_node = (edge.first << 1) | p;
            int weight = d + edge.second;

            if (weight < dist[adj_node])
            {
                dist[adj_node] = weight;
                queue.push(make_pair(-weight, adj_node));
            }
        }
    }
    if(dist[end << 1] == INF) dist[end << 1] = -1;
    cout << dist[end << 1] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    while(cin >> n >> m){
		vector<vector<pair<int, int>>> graph(n + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}
		dijkstra(graph, 1, n);
	}
}
