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
    int n, m, sx, sy; cin >> n >> m >> sx >> sy;

    vii h(n);
    rep(i, 0, n) cin >> h[i].f >> h[i].s; 

    vector<pair<char, int>> mov(m);
    rep(i, 0, m) cin >> mov[i].f >> mov[i].s;

    map<int, vii> mpx, mpy;
    rep(i, 0, n){
        int x = h[i].f, y = h[i].s;
        mpx[x].pb({y, i});
        mpy[y].pb({x, i});
    }

    for(auto i : mpx) sort(all(i.s), 
    [](auto& a, auto& b){return a.f < b.f;});
    for(auto i : mpy) sort(all(i.s),
    [](auto& a, auto& b){return a.f < b.f;});

    set<int> st;
    int currx = sx, curry = sy;
    auto lb_vec = [&](auto &vec, int val){
        return (int)(lower_bound(all(vec), make_pair(val, -1LL),
               [](auto &a, auto &b){ return a.first < b.first; }) - vec.begin());
    };

    rep(i,0, m){
        char d = mov[i].f;
        int c = mov[i].s;
        if(d == 'U' || d == 'D'){
            int ny = (d == 'U') ? (curry + c) : (curry - c);
            int minY = min(curry, ny), maxY = max(curry, ny);
            if(mpx.count(currx)){
                auto &lst = mpx[currx];
                int li = lb_vec(lst, minY);
                int hi = lb_vec(lst, maxY + 1) - 1;
                for(int j = li; j <= hi && j < (int)lst.size(); j++){
                    st.insert(lst[j].second);
                }
            }
            curry = ny;
        }
        else{
            int nx = (d == 'R') ? (currx + c) : (currx - c);
            int minX = min(currx, nx), maxX = max(currx, nx);
            if(mpy.count(curry)){
                auto &lst = mpy[curry];
                int li = lb_vec(lst, minX);
                int hi = lb_vec(lst, maxX + 1) - 1;
                for(int j = li; j <= hi && j < (int)lst.size(); j++){
                    st.insert(lst[j].second);
                }
            }
            currx = nx;
        }
    }

    cout << currx << " " << curry << " " << sz(st) << "\n";
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