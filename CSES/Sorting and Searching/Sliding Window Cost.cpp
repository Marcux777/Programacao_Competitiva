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

struct node {
    int count = 0;
    ll sum = 0;
};

node merge(node a, node b) {
    return {a.count + b.count, a.sum + b.sum};
}

struct SegTree {
    vector<node> tree;
    int n;

    SegTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void update(int idx, int val, int add, int l = 0, int r = -1, int pos = 1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[pos].count += add;
            tree[pos].sum += (ll)val * add;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, add, l, mid, 2 * pos);
        else
            update(idx, val, add, mid + 1, r, 2 * pos + 1);
        tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
    }

    int getKth(int k, int l = 0, int r = -1, int pos = 1) {
        if (r == -1) r = n - 1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (tree[2 * pos].count >= k)
            return getKth(k, l, mid, 2 * pos);
        return getKth(k - tree[2 * pos].count, mid + 1, r, 2 * pos + 1);
    }

    node query(int ql, int qr, int l = 0, int r = -1, int pos = 1) {
        if (r == -1) r = n - 1;
        if (ql > r || qr < l) return {0, 0};
        if (ql <= l && r <= qr) return tree[pos];
        int mid = (l + r) / 2;
        return merge(query(ql, qr, l, mid, 2 * pos),
                    query(ql, qr, mid + 1, r, 2 * pos + 1));
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vi vals= a;
    sor(vals);
    Unique(vals);

    int m = sz(vals);

    auto getIdx = [&](int x) {
        return LB(vals, x);
    };

    SegTree seg(m);

    rep(i, 0, k){
        seg.update(getIdx(a[i]), a[i], 1);
    }

    auto getCost = [&]() {
        int kth = (seg.tree[1].count + 1) / 2;
        int medIdx = seg.getKth(kth, 0, m - 1, 1);
        int med = vals[medIdx];
        
        node leftNode = seg.query(0, medIdx, 0, m - 1, 1);
        node rightNode = seg.query(medIdx + 1, m - 1, 0, m - 1, 1);

        int cost = med * leftNode.count - leftNode.sum +
                   rightNode.sum - med * rightNode.count;
        return cost;
    };

    cout << getCost() << " ";

    rep(i, k, n){
        seg.update(getIdx(a[i - k]), a[i - k], -1);
        seg.update(getIdx(a[i]), a[i], 1);
        cout << getCost() << " ";
    }
    cout << endl;

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
