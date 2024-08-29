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

int n, m, c;
vvi adj;
vi mo;
vvi dp;

int f(int a, int b){
    if(b <= 0) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    int ans = 0;
    for(auto v : adj[a])
        ans = max(ans, f(v, b-1));

    if(a == 1) ans = max(ans, f(a, b-1));
    return dp[a][b] = ans + mo[a-1];
}

void solve()
{
    cin >> n >> m >> c;
    mo = vi (n);
    adj = vvi(n+1);
    dp = vvi(n+1, vi(m+1, -1));
    for(auto &i : mo) cin >> i;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        ans = max(ans, f(1, i) - c * i*i);
    }

    cout << ans << endl;
    

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