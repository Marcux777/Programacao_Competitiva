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


void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;

    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    sort(all(c), greater<int>());
    // Estado: valor, i, j, k
    using State = tuple<int, int, int, int>;
    auto cmp = [](const State &s1, const State &s2) {
        return get<0>(s1) < get<0>(s2);
    };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
    // modificar a hash
    struct Hash {
        size_t operator()(const tiii& t) const {
            auto [i, j, k] = t;
            size_t res = 17;
            res = res * 31 + hash<int>()(i);
            res = res * 31 + hash<int>()(j);
            res = res * 31 + hash<int>()(k);
            return res;
        }
    };

    unordered_set<tiii, Hash> vis;

    auto push_state = [&](int i, int j, int k) {
        if(i < n && j < n && k < n) {
            tuple<int, int, int> idx = make_tuple(i, j, k);
            if (!vis.count(idx)) {
                vis.insert(idx);
                int v = a[i]*b[j] + b[j]*c[k] + c[k]*a[i];
                pq.push(make_tuple(v, i, j, k));
            }
        }
    };

    push_state(0, 0, 0);

    int ans = 0;
    rep (cnt, 0, k) {
        auto [val, i, j, l] = pq.top();
        pq.pop();
        ans = val;
        push_state(i+1, j, l);
        push_state(i, j+1, l);
        push_state(i, j, l+1);
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
