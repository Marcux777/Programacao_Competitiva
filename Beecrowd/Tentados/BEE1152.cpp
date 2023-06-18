#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Edge {
    int src, dest, weight;
};

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int KruskalMST(int V, vector<Edge>& edges) {
    int maxCost = 0;
    vector<Edge> result;
    
    // Ordena as arestas em ordem crescente de peso
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int* parent = new int[V];
    memset(parent, -1, sizeof(int) * V);

    for (unsigned int i = 0; i < edges.size(); i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) {
            result.push_back(edges[i]);
            Union(parent, x, y);
            maxCost += edges[i].weight;
        }
    }

    return maxCost;
}

int main() {
    int n, m;
    while (cin >> m >> n && m && n) {
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        int maxCost = KruskalMST(m, edges);
        cout << maxCost << endl;
    }

    return 0;
}
