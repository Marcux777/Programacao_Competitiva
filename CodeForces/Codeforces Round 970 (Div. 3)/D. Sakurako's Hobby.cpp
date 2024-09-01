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


vvi adj, radj;
vector<bool> vis;
stack<int> st;
vi color;

void dfs1(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]) dfs1(v);
    }
    st.push(u);
}

void dfs2(int u, vi& componente){
    vis[u] = 1;
    componente.pb(u);
    for(auto v : adj[u]){
        if(!vis[v]) dfs2(v, componente);
    }
}

void solve()
{
    int n; cin >> n;
    vi p(n);
    string s;
    for(auto &i : p) cin >> i;
    cin >> s;

    while(st.size()) st.pop();
    adj.clear();
    radj.clear();
    color.clear();
    vis.clear();
    vis.assign(n+1, 0);
    adj.resize(n+1), radj.resize(n+1);

    for(int i = 1; i <= n; i++){
        adj[i].pb(p[i-1]);
        radj[p[i-1]].pb(i);
    }

    color = vi(n+1);
    for(int i = 1; i <= n; i++){
        color[i] = (s[i-1] - '0') ? 0 : 1;
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs1(i);
    }
    vis = vector<bool>(n+1, 0);
    vi ans(n+1);
    while(st.size()){
        int u = st.top();
        st.pop();
        if(vis[u]) continue;
        vi componente;
        dfs2(u, componente);
        int cnt = 0;
        for(auto i : componente){
            cnt += color[i];
        }
        for(auto i : componente){
            ans[i] = cnt;
        }
    }
    for(auto i = 1; i <= n; i++) cout <<ans[i] << " ";
    cout << endl;
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}