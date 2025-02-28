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


tuple<int,int, bool> sim(int pos, const string &s) {
    int t = 0;
    for (char c : s) {
        t++;
        if (c == 'L') pos--;
        else pos++;
        if (pos == 0) {
            return {0, t, true};
        }
    }
    return {pos, t, false};
}

bool sim2(int start, const string &s, int limit) {
    int pos = start;
    rep(i, 0, min(limit, sz(s))) {
        if (s[i] == 'L') pos--;
        else pos++;
        if (pos == 0) return true;
    }
    return false;
}

void solve() {
    int n, k;
    int x;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    auto ciclo = [&](int pos) -> pii {
        ll t = 0;
        for(char c : s){
            t++;
            if(c=='L') pos--; else pos++;
            if(pos==0) return {t, 0};
        }
        return {t, pos};
    };

    auto parcial = [&](int pos, ll lim){
        rep(i,0, min(lim, sz(s))){
            if(s[i]=='L') pos--; else pos++;
            if(pos==0) return true;
        }
        return false;
    };

    ll ans = 0, usado = 0;

    auto [t1, p1] = ciclo(x);
    if(p1 != 0){
        if(t1 > k) ans = parcial(x, k) ? 1 : 0;
        cout << ans << endl;
        return;
    }
    ans++;
    usado += t1;
    if(usado >= k){ cout << ans << endl; return; }

    auto [t, p2] = ciclo(0);
    if(p2 != 0){
        cout << ans << endl;
        return;
    }

    int r = k - usado;
    int cheio = r / t;
    ans += cheio;
    usado += cheio * t;

    int sobra = k - usado;
    if(sobra > 0 && parcial(0, sobra)) ans++;

    cout << ans << endl;
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    cin >> tt;
    while (tt --> 0)
        solve();
    return 0;
}
