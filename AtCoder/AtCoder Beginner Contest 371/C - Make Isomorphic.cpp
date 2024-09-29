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
    int n, mg, mh;
    cin >> n;
    vvi g(n, vi(n)), h(n, vi(n)), cost(n, vi(n));
    cin >> mg;
    rep(i, 0, mg)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = 1;
    }

    cin >> mh;

    rep(i, 0, mh)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        h[a][b] = h[b][a] = 1;
    }
    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }

    vi perm(n);
    rep(i, 0, n) perm[i] = i;

    int min_cost = LINF;
    do {
        int curr = 0LL;
        rep(i, 0, n) rep(j, i + 1, n) {
            if (g[i][j] != h[perm[i]][perm[j]])
                curr += cost[perm[i]][perm[j]];
        }
        min_cost = min(min_cost, curr);
    } while (next_permutation(all(perm)));


    cout << min_cost << endl;
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
