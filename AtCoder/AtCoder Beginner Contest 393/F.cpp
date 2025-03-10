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

// https://cp-algorithms.com/data_structures/segment_tree.html#preserving-the-history-of-its-values-persistent-segment-tree

class PersSegTree {
public:
    struct Vertex {
        Vertex *l, *r;
        int val;
        Vertex(int val) : l(nullptr), r(nullptr), val(val) {}
        Vertex(Vertex *l, Vertex *r) : l(l), r(r) {
            val = max(l ? l->val : 0, r ? r->val : 0);
        }
    };

    PersSegTree(int tl, int tr) : tl(tl), tr(tr) {
        base = build(tl, tr);
    }

    Vertex* getBase() {
        return base;
    }

    int query(Vertex* v, int l, int r) {
        return get_max(v, tl, tr, l, r);
    }

    Vertex* update(Vertex* v, int pos, int new_val) {
        return update(v, tl, tr, pos, new_val);
    }

private:
    int tl, tr;
    Vertex* base;

    Vertex* build(int tl, int tr) {
        if (tl == tr)
            return new Vertex(0);
        int tm = (tl + tr) / 2;
        return new Vertex(build(tl, tm), build(tm + 1, tr));
    }

    int get_max(Vertex* v, int tl, int tr, int l, int r) {
        if(l > r)
            return 0;
        if(tl == l && tr == r)
            return v->val;
        int tm = (tl + tr) / 2;
        return max(get_max(v->l, tl, tm, l, min(r, tm)),
                   get_max(v->r, tm + 1, tr, max(l, tm + 1), r));
    }

    Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
        if(tl == tr)
            return new Vertex(max(v->val, new_val));
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
        else
            return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
    }
};
void solve()
{
    int n, q; cin >> n >> q;
    vi a(n);
    for(auto &i : a) cin >> i;
    // compressao de coordenadas
    vi comp = a;
    sor(comp);
    Unique(comp);
    PersSegTree pst(1, MAXN);
    vector<PersSegTree::Vertex*> roots(n);

    PersSegTree::Vertex* base = pst.getBase();

    rep(i, 0, n){
        int pos = LB(comp, a[i]) + 1;
        int best = 0;
        if(pos > 1)
            best = (i == 0 ? pst.query(base, 1, pos-1) : pst.query(roots[i-1], 1, pos-1));
        int cur = best + 1;
        roots[i] = pst.update((i == 0 ? base : roots[i-1]), pos, cur);
    }

    rep(i, 0, q){
        int r, x;
        cin >> r >> x;
        int pos = UB(comp, x);
        if(pos == 0)
            cout << 0 << endl;
        else
            cout << pst.query(roots[r-1], 1, pos) << endl;
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
