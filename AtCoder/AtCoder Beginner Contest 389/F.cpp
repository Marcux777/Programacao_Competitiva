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

int op(int a, int b) { return max(a, b); }
int e() { return -1e9; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

struct LazySegTree {
    private:
        int n, size, log;
        vector<int> d, lz;
        
        void update(int k) { d[k] = op(d[2*k], d[2*k+1]); }
        
        void all_apply(int k, int f) {
            d[k] = mapping(f, d[k]);
            if (k < size) lz[k] = composition(f, lz[k]);
        }
        
        void push(int k) {
            if (lz[k] == id()) return;
            all_apply(2*k, lz[k]);
            all_apply(2*k+1, lz[k]);
            lz[k] = id();
        }

    public:
        template <class F>
        int max_right(int l, F f) {
            if (l == n) return n;
            l += size;
            for (int i = log; i >= 1; i--) push(l >> i);
            int sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!f(op(sm, d[l]))) {
                    while (l < size) {
                        push(l);
                        l = 2 * l;
                        if (f(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return n;
        }
        LazySegTree(int n_) : LazySegTree(vector<int>(n_, e())) {}
        
        LazySegTree(const vector<int>& v) {
            n = v.size();
            log = 0;
            while ((1<<log) < n) log++;
            size = 1<<log;
            d = vector<int>(2*size, e());
            lz = vector<int>(size, id());
            for (int i = 0; i < n; i++) d[size+i] = v[i];
            for (int i = size-1; i >= 1; i--) update(i);
        }
        
        void set(int p, int x) {
            p += size;
            for (int i = log; i >= 1; i--) push(p>>i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p>>i);
        }
        
        int get(int p) {
            p += size;
            for (int i = log; i >= 1; i--) push(p>>i);
            return d[p];
        }
        
        int prod(int l, int r) {
            if (l >= r) return e();
            l += size;
            r += size;
            for (int i = log; i >= 1; i--) {
                if (((l>>i)<<i) != l) push(l>>i);
                if (((r>>i)<<i) != r) push((r-1)>>i);
            }
            int sml = e(), smr = e();
            while (l < r) {
                if (l&1) sml = op(sml, d[l++]);
                if (r&1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }
        
        void apply(int l, int r, int f) {
            if (l >= r) return;
            l += size;
            r += size;
            for (int i = log; i >= 1; i--) {
                if (((l>>i)<<i) != l) push(l>>i);
                if (((r>>i)<<i) != r) push((r-1)>>i);
            }
            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if (l&1) all_apply(l++, f);
                    if (r&1) all_apply(--r, f);
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }
            for (int i = 1; i <= log; i++) {
                if (((l>>i)<<i) != l) update(l>>i);
                if (((r>>i)<<i) != r) update((r-1)>>i);
            }
        }
};


void solve()
{
    int n;
    cin >> n;
    vi l(n), r(n);
    rep(i, 0, n) cin >> l[i] >> r[i];

    vi rate(500000, 0);
    iota(all(rate), 1);
    LazySegTree lz(rate);

    rep(i, 0, n){
        auto L = lz.max_right(0, [&](int x){return x < l[i];});
        auto R = lz.max_right(0, [&](int x){return x <= r[i];});
        lz.apply(L, R, 1);
    }
    int q;
    cin >> q;
    while(q--){
        int x; cin >> x;
        cout << lz.get(x-1) << endl;
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