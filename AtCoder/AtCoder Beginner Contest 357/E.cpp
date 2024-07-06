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

vvi adj;
vi dp;
vi visited;

int dfs(int u) {
    if (visited[u]) return dp[u];
    visited[u] = 1;
    dp[u] = 1; // O próprio vértice é alcançável
    for (auto v : adj[u]) {
        if(!visited[v])
            dp[u] += dfs(v);
    }
    return dp[u];
}

void solve() {
    int n; 
    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        adj[i].pb(x);
    }
    
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += dfs(i)-1;
    }
    
    cout << count << endl;
}

int32_t main() {
    IOS;
    int tt;
    tt = 1;
    while (tt--)
        solve();
    return 0;
}