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

vvi graph;
vi vis;
unordered_set<int> st;
int c = 0;

pair<int, int> dfs(int u, int p, int K) {
    int c = vis[u], ans = 0;
    bool ok = true;
    for (int v : graph[u]) {
        if (v != p) {
            auto [c_sub, ans_sub] = dfs(v, u, K);
            c += c_sub;
            ans += ans_sub;
            ok &= c_sub < K;
        }
    }
    ans += ok && (c > 0);
    return {c, ans};
}

void solve()
{
    int n, k;
    cin >> n >> k;
    c = 0;
    vi v(k);
    graph.resize(n+1);
    vis.resize(n+1, 0);

    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    
    for(auto &i : v) {
        cin >> i;
        st.insert(i);
        vis[i] = 1;
    }

    cout << dfs(v[0], -1, k).second << endl;


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