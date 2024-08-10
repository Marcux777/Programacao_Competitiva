#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inf LLONG_MAX

vector<vector<pair<int, int>>> adj;


int Prim(int s = 1) {
    int n = adj.size();
    vector<int> key(n, inf);
    vector<bool> mstSet(n, false);
    vector<int> parent(n, -1);

    key[s] = 0;

    set<pair<int, int>> pq; // Pode-se usar Priority_queue também
    pq.insert({0, s});

    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        mstSet[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!mstSet[v] && weight < key[v]) {
                pq.erase({key[v], v});
                key[v] = weight;
                pq.insert({key[v], v});
                parent[v] = u;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += key[i];
    }

    return ans;
}

signed main(){
    int n, m; cin >> n >> m;
    adj.resize(n);

    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    cout << Prim() << endl;
}