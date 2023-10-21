#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});

    while (!queue.empty()) {
        int current_node = queue.top().second;
        queue.pop();

        for (auto edge : graph[current_node]) {
            int adj_node = edge.first;
            int weight = edge.second;

            if (dist[current_node] + weight < dist[adj_node]) {
                dist[adj_node] = dist[current_node] + weight;
                queue.push({dist[adj_node], adj_node});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("saida.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int x; 
    cin >> x;
    vector<int> dist = dijkstra(graph, x, n);

    sort(dist.begin(), dist.end());

    cout << dist[n-1] - dist[1] << endl;

    return 0;
}
