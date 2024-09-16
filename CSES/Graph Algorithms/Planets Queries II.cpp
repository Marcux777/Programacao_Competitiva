#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
const int MAXN = 2e5 + 5;
const int LOG = 20;
const int INF = 1e18;

int n, q;
vi tel(MAXN);
vvi up(MAXN, vi(LOG));
vi scc_id(MAXN), scc_size(MAXN), dist(MAXN);
vector<bool> visited(MAXN);
stack<int> st;
int scc_count = 0;

void tarjan(int u, int& time, vi& disc, vi& low, vvi& adj) {
    disc[u] = low[u] = ++time;
    st.push(u);
    visited[u] = true;

    int v = tel[u];
    if (disc[v] == -1) {
        tarjan(v, time, disc, low, adj);
        low[u] = min(low[u], low[v]);
    } else if (visited[v]) {
        low[u] = min(low[u], disc[v]);
    }

    if (low[u] == disc[u]) {
        while (st.top() != u) {
            int v = st.top();
            st.pop();
            visited[v] = false;
            scc_id[v] = scc_count;
            scc_size[scc_count]++;
        }
        st.pop();
        visited[u] = false;
        scc_id[u] = scc_count;
        scc_size[scc_count]++;
        scc_count++;
    }
}

void preprocess() {
    for (int i = 1; i <= n; ++i) {
        up[i][0] = tel[i];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    vi disc(n + 1, -1), low(n + 1, -1);
    int time = 0;
    for (int i = 1; i <= n; ++i) {
        if (disc[i] == -1) {
            tarjan(i, time, disc, low, up);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (scc_size[scc_id[i]] > 1) {
            dist[i] = 0;
        } else {
            dist[i] = INF;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == 0) {
            queue<int> que;
            que.push(i);
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                int v = tel[u];
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    que.push(v);
                }
            }
        }
    }
}

int min_teleports(int a, int b) {
    if (scc_id[a] == scc_id[b]) {
        return dist[b] - dist[a];
    }
    if (a == b) return 0;
    int steps = 0;
    for (int j = LOG - 1; j >= 0; --j) {
        if (up[a][j] != 0 && scc_id[up[a][j]] != scc_id[b]) {
            a = up[a][j];
            steps += (1 << j);
        }
    }
    a = up[a][0];
    return (scc_id[a] == scc_id[b]) ? steps + 1 : -1;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> tel[i];
    }

    preprocess();

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << min_teleports(a, b) << endl;
    }
}

int32_t main() {
    IOS;
    solve();
    return 0;
}