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
#define Unique(v)                     \
    sort(all(v));                     \
    v.erase(unique(all(v)), v.end()); \
    v.shrink_to_fit()
#define sz(v) ((int)v.size())
#define sor(x) sort(all(x))
#define ft front()
#define bk back()
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
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

class DSU {
public:
    vector<int> parent, size;
    vector<multiset<int>> topK; // Multiset para armazenar os K maiores vértices

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        topK.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            topK[i].insert(i); // Inicialmente, cada vértice está em sua própria componente
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];

        // Mesclar os conjuntos topK
        for (int v : topK[y]) {
            topK[x].insert(v);
            if (topK[x].size() > 10) {
                topK[x].erase(topK[x].begin()); // Manter apenas os 10 maiores
            }
        }
        topK[y].clear(); // Limpar o conjunto da componente menor
    }

    int getKthLargest(int v, int k) {
        int root = find(v);
        if (topK[root].size() < k) return -1;
        auto it = topK[root].rbegin();
        advance(it, k - 1);
        return *it;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    vector<set<int>> comp(n + 1);
    rep(i, 1, n+1){
        comp[i].insert(i);
    }
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            dsu.unite(u, v);
        } else {
            cout << dsu.getKthLargest(u, v) << endl;
        }
    }
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