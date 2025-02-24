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
const int LOGN = 21;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl


struct Edge {
    int to, cap, flow, rev;
};

struct Dinic {
    int N;
    vector<vector<Edge>> graph;
    vector<int> level, start;

    Dinic(int N): N(N), graph(N+1), level(N+1), start(N+1) {}

    void addEdge(int u, int v, int cap) {
        Edge a = {v, cap, 0, (int)graph[v].size()};
        Edge b = {u, 0, 0, (int)graph[u].size()};
        graph[u].push_back(a);
        graph[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &e: graph[u]){
                if(level[e.to] < 0 && e.flow < e.cap) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int u, int t, int flow) {
        if(u == t) return flow;
        for(int &i = start[u]; i < graph[u].size(); i++){
            Edge &e = graph[u][i];
            if(level[e.to] == level[u] + 1 && e.flow < e.cap) {
                int curr_flow = min(flow, e.cap - e.flow);
                int temp_flow = dfs(e.to, t, curr_flow);
                if(temp_flow > 0){
                    e.flow += temp_flow;
                    graph[e.to][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while(bfs(s,t)){
            fill(start.begin(), start.end(), 0);
            while (int pushed = dfs(s,t,INT64_MAX))
                flow += pushed;
        }
        return flow;
    }
};

void findPath(int u, int t, vector<vector<Edge>>&graph, vi &path){
    path.pb(u);
    if(u ==t) return;

    for(auto &e : graph[u])
    {
        if(e.flow > 0){
            e.flow = 0; // remove a aresta
            findPath(e.to, t, graph, path);
            return;
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    Dinic dinic(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        dinic.addEdge(a, b, 1);
    }
    int k = dinic.maxFlow(1, n);
    cout << k << endl;
    rep(i, 0, k){
        vi path;
        findPath(1, n, dinic.graph, path);
        cout << sz(path) << endl;
        for(auto i : path) cout << i << " ";
        cout << endl;
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
