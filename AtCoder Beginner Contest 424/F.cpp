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

struct SegTree {
    int n, base, neutral;
    vector<int> st;
    function<int(int,int)> merge;

    void init(int N, int neutral_, function<int(int,int)> merge_) {
        n = N;
        neutral = neutral_;
        merge = std::move(merge_);
        base = 1;
        while (base < n) base <<= 1;
        st.assign(2 * base, neutral);
    }

    // ponto 1-indexado
    void update(int p, int v) {
        int i = p + base - 1;
        st[i] = v;
        for (i >>= 1; i; i >>= 1) {
            st[i] = merge(st[i << 1], st[i << 1 | 1]);
        }
    }

    // consulta em [l, r] 1-indexado
    int query(int l, int r) {
        if (l > r) return neutral;
        int L = l + base - 1, R = r + base - 1;
        int ansL = neutral, ansR = neutral;
        while (L <= R) {
            if (L & 1) ansL = merge(ansL, st[L++]);
            if (!(R & 1)) ansR = merge(st[R--], ansR);
            L >>= 1; R >>= 1;
        }
        return merge(ansL, ansR);
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    SegTree stmax;
    stmax.init(n, -LINF, [](int a, int b) { return max(a, b); });
    SegTree stmin;
    stmin.init(n, LINF, [](int a, int b) { return min(a, b); });
    rep(i,0,q){
        int a, b; cin >> a >> b;
        bool ok = false;
        if(a+1 <= b - 1){
            int mx = stmax.query(a+1, b-1);
            int mn = stmin.query(a+1, b-1);
            if(mx > b || mn < a) {
                ok = true;
            }
        }
        if(ok) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            stmax.update(a, b);
            stmin.update(b, a);
        }
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
