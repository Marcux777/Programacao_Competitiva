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
#define Unique(v) \
    sort(all(v)); \
    v.erase(unique(all(v)), v.end());
#define sz(v) ((int)v.size())
#define sor(x) sort(all(x))
#define ft front()
#define bk back()
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < (b); ++i)
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
    // Pode ser otimizada o espaço usado
    // nesse codigo passa, mas pode ser usado O(N), 
    // ao inves de O(N^2), como foi feito aqui
    int n; cin >> n;
    vector<double> v(n);
    rep(i, 0, n) cin >> v[i];

    vector<vector<double>> pd(n+1, vector<double>(n+1, 0.0));
    pd[0][0] = 1.0;

    rep(i, 0, n)
    {
        rep(j, 0, i+1)
        {
            pd[i+1][j] += pd[i][j] * (1 - v[i]);
            pd[i+1][j+1] += pd[i][j] * v[i];
        }
    }

    double ans = 0.0;

    for(int i = (n+1)/2; i <= n; i++)
    {
        ans += pd[n][i];
    }
    cout << fixed << setprecision(10) << ans << endl;
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