#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int MAXN = 1e5 + 5;
const int LOG = 20;
int depth[MAXN], parent[MAXN][LOG], dist[MAXN];
vector<pair<int, int>> g[MAXN];

void dfs(int u, int par) {
    parent[u][0] = par;
    for(int i = 1; i < LOG; i++) {
        if(parent[u][i-1] != -1) {
            parent[u][i] = parent[parent[u][i-1]][i-1];
        }
    }
    for(auto &it : g[u]) {
        if(it.first == par) continue;
        depth[it.first] = depth[u] + 1;
        dist[it.first] = dist[u] + it.second;
        dfs(it.first, u);
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int i = LOG - 1; i >= 0; i--) {
        if(parent[u][i] != -1 && depth[parent[u][i]] >= depth[v]) {
            u = parent[u][i];
        }
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("saida.txt", "w", stdout);
    int n;
    while(cin >> n && n) {
        for(int i = 0; i < n; i++) g[i].clear();
        memset(parent, -1, sizeof(parent));
        
        for(int i = 1; i < n; i++) {
            int a, w;
            cin >> a >> w;
            g[i].push_back({a, w});
            g[a].push_back({i, w});
        }
        
        depth[0] = dist[0] = 0;
        dfs(0, -1);
        
        int q;
        cin >> q;
        vector<int>resp;
        while(q--) {
            int s, t;
            cin >> s >> t;
            int ancestor = lca(s, t);
            resp.push_back(dist[s] + dist[t] - 2 * dist[ancestor]);
        }
        for(int i = 0; i <resp.size(); i++){
            cout << resp[i] << (i == resp.size() - 1 ? '\n' : ' ');
        }
    }
    
    return 0;
}
