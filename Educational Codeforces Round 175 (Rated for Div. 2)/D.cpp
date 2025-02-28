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
const int mod = 998244353;
const int LOGN = 21;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl


void solve()
{
    int n; cin >> n;
    vi a(n+1);
    rep(i, 2, n+1) cin >> a[i];
    vvi f(n+1);
    rep(i, 2, n+1){
        f[a[i]].pb(i);
    }
    vi d(n+1);
    d[1] = 0;

    function<void(int)> bfs = [&](int u){
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : f[u]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    };
    bfs(1);

    int hmax = 0;
    rep(i, 1, n+1) hmax = max(hmax, d[i]);

    vvi g(n+1);
    rep(i, 1, n+1){
        g[d[i]].pb(i);
    }

    vi dp(n+1);
    for(auto i : g[hmax]){
        dp[i] = 1;
    }
    for(int i = hmax - 1; i >= 0; i--){
        int sum = 0;
        for(int v : g[i + 1]) {
            sum = (sum + dp[v]) % mod;
        }
        for(int v : g[i]) {
            int sumf = 0;
            for(int u : f[v]) {
                sumf = (sumf + dp[u]) % mod;
            }
            if(v == 1) dp[v] = (1 + sum) % mod;
            else dp[v] = (1 + ((sum - sumf) % mod + mod) % mod) % mod;
        }
    }
    cout << dp[1] << endl;


}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    cin >> tt;
    while (tt --> 0)
        solve();
    return 0;
}
