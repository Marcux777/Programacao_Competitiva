#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define pb push_back
#define all(v) v.begin(), v.end()
#define f first
#define s second
#define Unique(v) \
    sort(all(v)); \
    v.erase(unique(all(v)), v.end());
#define sz(v) ((int)v.size())
#define sor(x) sort(all(x))
#define ft front()
#define bk back()
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef tuple<int, int, int> tiii;
const int MAXN = 2e5 + 5;
const int LOG = 20;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl


int depth[MAXN], parent[MAXN][LOG], dist[MAXN];
vii g[MAXN];

void dfs(int u, int par) {
    parent[u][0] = par;
    for(int i = 1; i < LOG; i++) {
        // tentando zerar o parent
        parent[u][i] = -1;
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
        for(int i = 0; i < n; i++)
            g[i].clear();
        //memset(parent, -1, sizeof(parent));
        
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
