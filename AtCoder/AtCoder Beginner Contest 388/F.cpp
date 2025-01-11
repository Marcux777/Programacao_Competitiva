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

bool ok(const pii &x,
        const pii &y,
        int A, int B)
{
    return (y.f <= x.s + B) && (y.s >= x.f + A);
}

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vii v(m);
    for (auto &i : v)
        cin >> i.f >> i.s;

    sor(v);

    {
        bool ok1 = false, ok2 = false;
        for (auto &b : v)
        {
            if (b.f <= 1 && 1 <= b.s)
                ok1 = true;
            if (b.f <= n && n <= b.s)
                ok2 = true;
        }
        if (ok1 || ok2)
        {
            cout << "No\n";
            return;
        }
    }

    vii good;
    
    {
        int curr = 1;
        for (auto &b : v)
        {
            if (b.f <= curr and curr <= b.s)
                continue;
            if (b.f > curr)
            {
                good.pb({curr, b.f - 1});
            }
            curr = b.s + 1;
            if (curr > n)
                break;
        }

        if (good.empty() or good.back().s < n)
        {
            if (good.empty())
            {
                if (curr <= n)
                    good.pb({curr, n});
            }
            else
            {
                if (curr <= n)
                    good.pb({curr, n});
            }
        }
    }

    int st = -1, end = -1;
    rep(i, 0, sz(good))
    {
        if (good[i].f <= 1 && 1 <= good[i].s)
            st = i;
        if (good[i].f <= n && n <= good[i].s)
            end = i;
    }
    if (st == -1 || end == -1)
    {
        cout << "No\n";
        return;
    }
    if (st == end)
    {
        cout << "Yes\n";
        return;
    }

    vvi adj(sz(good));
    rep(i, 0, sz(good))
    {
        rep(j, 0, sz(good))
        {
            if (i == j)
                continue;
            if (ok(good[i], good[j], a, b))
            {
                adj[i].pb(j);
            }
        }
    }
    vector<bool> vis(sz(good), false);
    queue<int> q;
    vis[st] = true;
    q.push(st);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == end)
        {
            cout << "Yes\n";
            return;
        }
        for (auto &nx : adj[u])
        {
            if (!vis[nx])
            {
                vis[nx] = true;
                q.push(nx);
            }
        }
    }

    cout << "No\n";
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