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

void dijkstra(const vector<vector<pair<int, int>>>& graph, const vector<int>& a, int start) {
    int n = graph.size();
    vector<ll> dist(n, LINF);
    dist[start] = a[start - 1];
    set<pair<ll, int>> queue;
    queue.insert({dist[start], start});

    while (!queue.empty()) {
        int current_node = queue.begin()->second;
        queue.erase(queue.begin());

        for (auto edge : graph[current_node]) {
            int adj_node = edge.first;
            ll weight = edge.second + a[adj_node - 1];

            if (dist[current_node] + weight < dist[adj_node]) {
                queue.erase({dist[adj_node], adj_node}); 
                dist[adj_node] = dist[current_node] + weight;
                queue.insert({dist[adj_node], adj_node});
            }
        }
    }

    for(int i = 2; i < n; i++) cout << dist[i] << " ";
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }
    
    dijkstra(graph, a, 1);
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