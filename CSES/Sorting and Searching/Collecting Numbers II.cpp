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
    int n, m; cin >> n >> m;
    vi a(n+1), pos(n+1);
    rep(i, 1, n+1){
        cin >> a[i];
        pos[a[i]] = i;
    }

    vector<bool> ok(n+2, false);
    int breaks = 0;
    rep(i, 1, n){
        ok[i] = (pos[i] < pos[i+1]);
        if(!ok[i])breaks++;
    }

    auto update = [&](int i) {
        if(i >= 1 and i < n) {
            bool newGood = (pos[i] < pos[i+1]);
            if(ok[i] != newGood) {
                if(ok[i] && !newGood) breaks++; // passou de bom para não bom
                else if(!ok[i] && newGood) breaks--; // passou de não bom para bom
                ok[i] = newGood;
            }
        }
    };

    while(m--){
        int x, y; cin >> x >> y;
        int u = a[x], v = a[y];
        set<int> idx;
        idx.insert(u);
        idx.insert(v);
        idx.insert(u-1);
        idx.insert(v-1);

        for(auto it = idx.begin(); it != idx.end(); ) {
            if(*it < 1 || *it >= n) {
                it = idx.erase(it);
            } else {
                ++it;
            }
        }
        swap(a[x], a[y]);
        swap(pos[u], pos[v]);

        for(auto i : idx){
            update(i);
        }
        cout << breaks+1 << endl;
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
