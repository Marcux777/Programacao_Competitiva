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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    int initx, inity;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (a[i][j] == 'A')
                initx = i, inity = j;
        }
    }

    vi dirx = {0, 0, 1, -1};
    vi diry = {1, -1, 0, 0};
    vector<char> dir = {'R', 'L', 'D', 'U'};
    queue<pii> q;
    q.push({initx, inity});
    vvi dist(n, vi(m, INF));
    dist[initx][inity] = 0;

    vector<vii> parent(n, vii(m, {-1, -1}));
    vector<vector<char>> path(n, vector<char>(m, ' '));

    while (q.size())
    {
        auto &[x, y] = q.front();
        q.pop();
        rep(i, 0, 4)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] == '#' or dist[nx][ny] != INF)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
            parent[nx][ny] = {x, y};
            path[nx][ny] = dir[i];
        }
    }

    int ex, ey;
    int d = LINF;
    ex = ey = -1;
    rep(i, 0, n){
        rep(j, 0, m){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(a[i][j] != INF && dist[i][j] < d){
                    ex = i, ey = j;
                    d = dist[i][j];
                }
            }
        }
    }
    if(ex == -1) cout << "NO" << endl, exit(0);
    string p;
    while(ex != initx || ey != inity){
        p.pb(path[ex][ey]);
        auto [nx, ny] = parent[ex][ey];
        ex = nx, ey = ny;
    }
    reverse(all(p));
    cout << "YES" << endl;
    cout << sz(p) << endl;
    cout << p << endl;
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
