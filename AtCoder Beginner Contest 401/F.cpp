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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i] << (i + 1 == v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define TXTIO                           \
    freopen("entrada.in", "r", stdin);\
    freopen("saida.out", "w", stdout)
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
const int LOGN = 21;

void solve()
{

    auto diametro = [](int st, int n, vvi& graph) -> pii{
        vi dist(n, INF);
        queue<int> q;
        q.push(st);
        dist[st] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v : graph[u]){
                if(dist[v] == INF){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int max_dist = 0, max_node = 0;
        rep(i, 0, n){
            if(dist[i] > max_dist){
                max_dist = dist[i];
                max_node = i;
            }
        }
        return make_pair(max_node, max_dist);
    };

    auto bfs = [](int st, int n, vvi&g){
        vi dist(n, INF);
        queue<int> q;
        q.push(st);
        dist[st] = 0;
        while(sz(q))
        {
            int u = q.front(); q.pop();
            for(auto v : g[u]){
                if(dist[v] == INF){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    int n; cin >> n;
    vvi graph1(n);
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        graph1[u-1].pb(v-1);
        graph1[v-1].pb(u-1);
    }
    int p, q;
    pii p1 = diametro(0, n, graph1);
    p = p1.f;
    p1 = diametro(p, n, graph1);
    q = p1.f;

    vi dist1 = bfs(p, n, graph1);
    vi dist2 = bfs(q, n, graph1);
    vi a1(n);
    rep(i, 0, n){
        a1[i] = max(dist1[i], dist2[i]);
    }

    cin >> n;
    vvi graph2(n);
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        graph2[u-1].pb(v-1);
        graph2[v-1].pb(u-1);
    }

    pii p2 = diametro(0, n, graph2);
    p = p2.f;
    p2 = diametro(p, n,graph2);
    q = p2.f;
    vi dist3 = bfs(p, n, graph2);
    vi dist4 = bfs(q, n, graph2);
    vi a2(n);
    rep(i, 0, n){
        a2[i] = max(dist3[i], dist4[i]);
    }
    int d = max(p1.s, p2.s);
    sor(a1), sor(a2);
    //cout << p1.f << " " << p2.f << endl;

    vi prefix(n+1, 0);
    rep(i, 0, n) prefix[i+1] = prefix[i] + a2[i];

    int ans = 0;
    for(auto a : a1){
        int b = d - a - 1;
        int idx = upper_bound(all(a2), b) - a2.begin();
        ans += idx * d;
        ans += prefix[n] - prefix[idx];
        ans += (n - idx) * (a + 1);
    }
    cout << ans << endl;
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    while (tt --> 0)
        solve();
    return 0;
}
