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

class FenwickTree {
    private:
        int n;
        vector<int> tree;
    public:
        // Cria uma BIT com n posições (0-indexado publicamente)
        FenwickTree(int n) : n(n), tree(n+1, 0) {}

        // Adiciona 'x' na posição p (0-indexada)
        void add(int p, int x) {
            for(++p; p <= n; p += p & -p)
                tree[p] += x;
        }

        // Soma prefixo [0, p), p em [0, n+1]
        int sum(int p) const {
            int res = 0;
            for(; p; p -= p & -p)
                res += tree[p];
            return res;
        }

        // Soma no intervalo [l, r)
        int range_sum(int l, int r) const {
            return sum(r) - sum(l);
        }
    };

void solve()
{
    int n, m; cin >> n >> m;
    vvi g(m);
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
        g[a[i]].pb(i);
    }

    int ans =0;

    FenwickTree fenw(m);
    for(auto  i: a){
        ans += fenw.range_sum(i+1, m);
        fenw.add(i, 1);
    }

    cout << ans << endl;
    rep(c, 1, m){
        int c1, c2; c1 = c2 = 0;
        auto &grupo = g[m-c];
        rep(i, 0, sz(grupo)){
            c1 += grupo[i] - i;
            c2 += (n - 1 - grupo[i]) - (sz(grupo) - 1 - i);
        }
        ans += c1 - c2;
        cout << ans << endl;
    }

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
