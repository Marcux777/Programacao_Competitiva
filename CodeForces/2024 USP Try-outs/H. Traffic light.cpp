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
const int MAXN = 2e5 + 5;
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

int n, m, t;
vector<viii> adj;

void dijsktra(int a, int b) {
    vi dist(n + 1, LINF);
    dist[a] = b;
    priority_queue<pii, vii, greater<pii>> pq;
    pq.emplace(dist[a], a);
    while (!pq.empty()) {    
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (auto &[v, p] : adj[u]) {
            auto &[x, y] = p;
            int new_dist = d;
            int curr = d % (x + y);
            if (curr >= x) {
                new_dist += (x + y) - curr;
            }

            if (dist[v] > new_dist) {
                dist[v] = new_dist;
                pq.emplace(dist[v], v);
            }
        }
    }
    cout << dist[n] << endl;
}


void solve()
{
    cin >> n >> m >> t;
    adj.resize(n + 1);
    for (int i = 0 ; i < m; i++){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        adj[u].pb({v, {x, y}});
        adj[v].pb({u, {x, y}});
    }

    dijsktra(1, t);
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    while (tt--)
        solve();
    return 0;
}