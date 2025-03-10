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

class Fenwick {
private:
    vector<int> fenw;
    int n;
public:
    Fenwick(int n) : n(n), fenw(n + 1, 0) {}
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            fenw[idx] += val;
    }
    int query(int idx) const {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += fenw[idx];
        return sum;
    }
};

void solve()
{
    int n; cin >> n;
    vi p(n);
    for(auto &i : p) cin >> i;

    vi pos(n+1);
    rep(i, 0, n) pos[p[i]] = i+1;

    Fenwick fenw(n);

    auto s = [&](ll x){
        return x * (x+1LL) / 2LL;
    };
    int ans = 0;
    for(int k = n; k >= 1; k--){
        int curr = pos[k] - fenw.query(pos[k]);

        if(curr > k){
            ans += (s(curr - 1) - s(k - 1));
        }else if (curr < k){
            ans += (s(k-1) - s(curr-1));
        }

        fenw.update(pos[k], 1);
    }
    cout << ans << endl;
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
