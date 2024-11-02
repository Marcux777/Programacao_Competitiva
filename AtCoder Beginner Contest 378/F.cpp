#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }

    vector<vector<int>> groups() {
        int n = parent.size();
        vector<int> leader_buf(n), group_size(n);
        for (int i = 0; i < n; ++i) {
            leader_buf[i] = find(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i)
            result[leader_buf[i]].push_back(i);
        result.erase(
            remove_if(result.begin(), result.end(),
                      [](const vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> u(N - 1), v(N - 1);
    vector<int> deg(N, 0);
    for (int i = 0; i < N - 1; ++i) {
        cin >> u[i] >> v[i];
        --u[i];
        --v[i];  // Convert to 0-based indexing
        deg[u[i]]++;
        deg[v[i]]++;
    }

    DSU d(N);
    vector<int> c2(N, 0);
    for (int i = 0; i < N - 1; ++i) {
        if (deg[u[i]] == 3 && deg[v[i]] == 3) {
            d.merge(u[i], v[i]);
        } else if (deg[u[i]] == 3 && deg[v[i]] == 2) {
            c2[u[i]]++;
        } else if (deg[u[i]] == 2 && deg[v[i]] == 3) {
            c2[v[i]]++;
        }
    }

    long long ans = 0;
    auto groups = d.groups();
    for (const auto& g : groups) {
        int c = 0;
        for (int v : g) {
            c += c2[v];
        }
        ans += static_cast<long long>(c) * (c - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
