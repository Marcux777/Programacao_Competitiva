#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<pair<int, int>>>& graph) {
    visited[node] = true;
    for (const auto& v : graph[node]) {
        int u = v.first;
        if (!visited[u]) {
            dfs(u, visited, graph);
        }
    }
}

bool isStronglyConnected(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        dfs(i, visited, graph);

        if (find(visited.begin(), visited.end(), false) != visited.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    while (cin >> n >> m && n && m) {
        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            graph[x - 1].emplace_back(y - 1, z);
            if (z == 2) {
                graph[y - 1].emplace_back(x - 1, z);
            }
        }

        cout << isStronglyConnected(graph) << endl;
    }

    return 0;
}
