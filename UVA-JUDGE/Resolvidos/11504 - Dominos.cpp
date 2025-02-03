/*
~~ Alguma parte/frase foda de um livro/mangá para dar sorte ~~

Uma vez eu gritei, gradualmente, perdi minha voz.
Uma vez eu chorei, gradualmente, perdi minhas lágrimas.
Uma vez eu sofri, gradualmente, me tornei capaz de suportar tudo.
Uma vez me alegrei, gradualmente, me tornei indiferente ao mundo.
E agora, tudo o que me resta é um rosto sem expressão,
meu olhar é tão firme quanto um monólito,
apenas a perseverança permanece no meu coração.
Este sou eu, um personagem insignificante,
Fang Yuan — A Perseverança.

*/
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

vi g[MAXN], rg[MAXN];
vector<bool> vis;
vi order;

void dfs1(int v)
{
    vis[v] = true;
    for (auto u : g[v])
        if (!vis[u])
            dfs1(u);
    order.pb(v);
}

void dfs2(int v, int cid, vi &comp_id)
{
    comp_id[v] = cid;
    for (auto u : rg[v])
        if (comp_id[u] == -1)
            dfs2(u, cid, comp_id);
}

int kosaraju(int n, vi &comp_id)
{
    vis.assign(n, false);
    order.clear();
    rep(i, 0, n)
        if (!vis[i])
            dfs1(i);

    reverse(all(order));
    comp_id.assign(n, -1);
    int cid = 0;
    for (auto v : order)
        if (comp_id[v] == -1) {
            dfs2(v, cid, comp_id);
            cid++;
        }
    return cid;
}

vvi condensation(int n, const vi &comp_id, int compCount)
{
    vvi condensed(compCount);
    vector<set<int>> temp(compCount);
    rep(u, 0, n)
        for (auto v : g[u])
            if (comp_id[u] != comp_id[v])
                temp[comp_id[u]].insert(comp_id[v]);

    rep(i, 0, compCount)
        for (auto v : temp[i])
            condensed[i].pb(v);

    return condensed;
}

void solve()
{
    int n, m; cin >> n >> m;
    rep(i, 0, n) {
        g[i].clear();
        rg[i].clear();
    }
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        rg[y].pb(x);
    }
    vi comp_id;
    int count = kosaraju(n, comp_id);
    auto condensed = condensation(n, comp_id, count);
    vi indegree(count, 0);
    rep (i, 0, count) {
        for (int v : condensed[i])
            indegree[v]++;
    }
    int ans = 0;
    rep (i, 0, count) {
        if (indegree[i] == 0)
            ans++;
    }
    cout << ans << endl;
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
