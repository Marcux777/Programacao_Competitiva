#include <bits/stdc++.h>

using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)

#define pii pair<int, bool>

signed main() {
    IOS;
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int x, y; cin >> x >> y;
    int timer = 0;
    vector<int> low, tin(n+1, 0);
    vector<bool> vis(n+1, false);
    function<pii(int, int)> dfs = [&](int u, int p) -> pii{
        vis[u] = true;
        tin[u] = low[u] = timer++;
        int child = 0;

        bool ok = (u == y);

        for(auto v : graph[u]){
            if(v == p) continue;

            if(vis[v]) low[v] = min(low[v], tin[u]);
            else{
                auto [a, b] = dfs(v, u);
                low[u] = min(low[u], a);
                child++;
            }
        }
    };

}
