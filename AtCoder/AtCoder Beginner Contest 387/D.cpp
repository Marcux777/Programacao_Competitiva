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
    int h, r;
    cin >> h >> r;
    vector<string> mat(h);
    int si, sj, gi, gj;
    for (int i = 0; i < h; ++i)
    {
        cin >> mat[i];
        for (int j = 0; j < r; ++j)
        {
            if (mat[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if (mat[i][j] == 'G')
            {
                gi = i;
                gj = j;
            }
        }
    }
    queue<tiii> q;
    vvvi vis(h, vvi(r, vi(2, -1)));
    q.push({si, sj, -1});
    vis[si][sj][0] = 0;
    vis[si][sj][1] = 0;
    int dirs[2][4] = {
        {-1, 0, 1, 0},
        {0, -1, 0, 1}};

    while (!q.empty())
    {
        auto [i, j, last] = q.front();
        q.pop();
        if (i == gi && j == gj)
        {
            cout << vis[i][j][last] << endl;
            return;
        }
        rep(d, 0, 2)
        {
            if (last != -1 && d == last)
                continue;
            rep(k, 0, 4)
            {
                int ni = i + dirs[d][k];
                int nj = j + dirs[d][k + 1];
                if (ni >= 0 && ni < h && nj >= 0 && nj < r && mat[ni][nj] != '#')
                {
                    if (vis[ni][nj][d] == -1)
                    {
                        vis[ni][nj][d] = vis[i][j][last == -1 ? d : last] + 1;
                        q.push({ni, nj, d});
                    }
                }
                k++;
            }
        }
    }
    cout << -1 << endl;
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