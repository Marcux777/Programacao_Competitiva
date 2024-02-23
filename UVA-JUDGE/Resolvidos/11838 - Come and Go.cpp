#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<pair<int, int>>>& graph) {
    visited[node] = true;
    for (const auto& neighborPair : graph[node]) {
        int neighbor = neighborPair.first;
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

bool isStronglyConnected(vector<vector<pair<int, int>>>& graph) {
    int numNodes = graph.size();

    for (int startNode = 0; startNode < numNodes; ++startNode) {
        vector<bool> visited(numNodes, false);
        dfs(startNode, visited, graph);

        if (find(visited.begin(), visited.end(), false) != visited.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numNodes, numEdges;
    while (cin >> numNodes >> numEdges && numNodes && numEdges) {
        vector<vector<pair<int, int>>> graph(numNodes);

        for (int i = 0; i < numEdges; ++i) {
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
