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

int h, w, k;
vvi grid;
int ans = 0;
vector<vector<bool>> vis;

const vii directions = { {-1,0}, {1,0}, {0,-1}, {0,1} };


void dfs(int i, int j, int p) {
    if (p == k) {
        ans++;
        return;
    }
    for(auto &dir : directions){
        int ni = i + dir.first;
        int nj = j + dir.second;
        if(ni >= 0 && ni < h && nj >= 0 && nj < w && grid[ni][nj] == 0 && !vis[ni][nj]){
            vis[ni][nj] = true;
            dfs(ni, nj, p + 1);
            vis[ni][nj] = false;
        }
    }
}

void solve()
{
    
    cin >> h >> w >> k;
    grid = vvi(h, vi(w));
    rep(i, 0, h){
        string s; cin >> s;
        rep(j, 0, w)
            grid[i][j] = (s[j] == '.' ? 0 : 1);
    }

    vis = vector<vector<bool>>(h, vector<bool>(w, false));
    rep(i, 0, h){
        rep(j, 0, w){
            if(grid[i][j] == 1) continue;
            vis[i][j] = true;
            dfs(i, j, 0);
            vis[i][j] = false;
        }
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