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

struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find_set(int x){
        if(parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y){
        int fx = find_set(x);
        int fy = find_set(y);
        if(fx != fy){
            if(size[fx] < size[fy]){
                parent[fx] = fy;
                size[fy] += size[fx];
            }
            else{
                parent[fy] = fx;
                size[fx] += size[fy];
            }
        }
    }
};

bool isLucky(int x){
    while(x){
        if(x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

void solve()
{
    int n; cin >> n;
    UnionFind uf(n);
    rep(i, 0, n - 1)
    {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        if(!isLucky(w)){
            uf.union_set(u, v);
        }
    }

    vi s(n);
    rep(i, 0, n){
        s[i] = uf.size[uf.find_set(i)];
    }
    int ans = 0;
    rep(j, 0, n){
        int val = (n - s[j]);
        ans += val * (val - 1);
    }

    cout << ans << endl;
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