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
const int MAXN = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 998244353;
const int LOGN = 21;

vi fact, invfact;

int exp(int a, int b, int m){
    int res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % m;

        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


void computefac(int n, vi& fact, vi& invfact)
{
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    rep (i, 1, n+1)
        fact[i] = (fact[i - 1] * i) % mod;

    invfact[n] = exp(fact[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}

void solve()
{
    vi a(26);
    int sum = 0;
    for(auto&i : a){
        cin >> i;
        sum += i;
    }

    if(sum == 0) {cout << 0 << endl; return;}

    int n = sum;
    int o = (n+1)/2, e = n/2;

    vi dp(o+1, 0);
    dp[0] = 1;
    rep(i, 0, 26){
        if(a[i] == 0) continue;
        for(int j = o; j >= a[i]; j--){
            dp[j] = (dp[j] + dp[j - a[i]])%mod;
        }
    }

    if(dp[o] == 0) {cout << 0 << endl; return;}

    int w = (1LL * fact[o] * fact[e]) % mod;
    rep(i, 0, 26){
        w = (w * invfact[a[i]]) % mod;
    }
    cout << (1LL * w * dp[o]) % mod << endl;


}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    computefac(MAXN, fact, invfact);
    cin >> tt;
    while (tt --> 0)
        solve();
    return 0;
}
