#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph {
    vector<pair<double, pair<int, int>>> edgelist;
    int V;

public:
    Graph(int V) : V(V) {}

    void addEdge(int x, int y, double w) {
        edgelist.emplace_back(w, make_pair(x, y));
    }

    double kruskals_mst() {
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>> pq;

        for (auto edge : edgelist)
            pq.push(edge);

        DSU s(V);
        double ans = 0;
        while (!pq.empty()) {
            double w = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

double distance(double a, double b, double p, double q) {
    double dx = a - p;
    double dy = b - q;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        Graph g(n + 1);
        vector<pair<double, double>> posicao(n);
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            posicao[i] = {x, y};
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = distance(posicao[i].first, posicao[i].second, posicao[j].first, posicao[j].second);
                g.addEdge(i, j, dist);
            }
        }
        cout << fixed << setprecision(2) << g.kruskals_mst() << endl;
    }
}
