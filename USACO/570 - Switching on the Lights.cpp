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
    freopen("lightson.in", "r", stdin);\
    freopen("lightson.out", "w", stdout)
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

void solve()
{
    int n, m;cin >>n>>m;

    vector<vector<vector<pii>>> mp(n+1, vector<vector<pii>>(n+1));

    rep(i, 0, m){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        mp[x][y].pb({a, b});
    }

    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};

    vvi aceso(n+1, vi(n+1, 0));
    vvi vis(n+1, vi(n+1, 0));
    aceso[1][1] = vis[1][1] = 1;
    int ans = 1;

    queue<pii> q;
    q.push({1, 1});

    while(sz(q)){
        auto [x, y] = q.front();
        q.pop();
        for(auto [a, b] : mp[x][y]){
            if(!aceso[a][b]){
                aceso[a][b] = 1;
                ans++;

                rep(k, 0, 4){
                    int nx = a + dx[k];
                    int ny = b + dy[k];
                    if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && vis[nx][ny]){
                        q.push({nx, ny});
                        vis[a][b] = 1;
                        q.push({a, b});
                        break;
                    }
                }
            }
        }
        rep(i, 0, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && aceso[nx][ny]){
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    IOS;
    TXTIO;
    int tt;
    tt = 1;
    while (tt --> 0)
        solve();
    return 0;
}
