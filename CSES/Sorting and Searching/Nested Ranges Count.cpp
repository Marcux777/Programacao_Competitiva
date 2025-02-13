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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
    using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

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

struct BIT {
    int n;
    vector<int> fenw;
    BIT(int n) : n(n), fenw(n + 1, 0) {}

    void update(int i, int delta) {
        for(; i <= n; i += i & (-i))
            fenw[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for(; i > 0; i -= i & (-i))
            sum += fenw[i];
        return sum;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<tiii> intervals(n);
    vi coords;
    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        intervals[i] = {l, r, i};
        coords.pb(r);
    }
    // Coordinate compression
    sor(coords);
    Unique(coords);
    auto getIndex = [&](int r) {
        return (int)(LB(coords, r)) + 1;
    };

    vi ans1(n), ans2(n);

    sort(all(intervals), [&](tiii a, tiii b) {
        return get<0>(a) == get<0>(b) ? get<1>(a) > get<1>(b) : get<0>(a) < get<0>(b);
    });
    BIT bit1(sz(coords));
    for (int i = n - 1; i >= 0; i--) {
        int idx = getIndex(get<1>(intervals[i]));
        ans1[get<2>(intervals[i])] = bit1.query(idx);
        bit1.update(idx, 1);
    }
    //sort(all(intervals), [&](tiii a, tiii b) {
    //    return get<0>(a) == get<0>(b) ? get<1>(a) < get<1>(b) : get<0>(a) < get<0>(b);
    //});
    BIT bit2(sz(coords));
    rep(i, 0, n) {
        int idx = getIndex(get<1>(intervals[i]));
        ans2[get<2>(intervals[i])] = bit2.query(sz(coords)) - bit2.query(idx - 1);
        bit2.update(idx, 1);
    }

    for (auto i : ans1) cout << i << " ";
    cout << "\n";
    for (auto i : ans2) cout << i << " ";
    cout << "\n";
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
