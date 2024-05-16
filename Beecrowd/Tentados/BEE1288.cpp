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
#define fopen() freopen("texto.txt", "w", stdout)
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
vector<vi> dp;
vi a, b;
int k, r, n;

int f(int id, int w){
    if(id >= n) return 0;
    if(w > k) return 0;
    if(dp[id][w] != -1) return dp[id][w];

    int r1 = f(id+1, w);
    if(b[id] + w <= k){
        int r2 = f(id+1, w+b[id]) + a[id];
        r1 = max(r1, r2);
    }
    return dp[id][w] = r1;
}

void solve()
{
    cin >> n;
    a = vi(n);
    b = vi(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    cin >> k >> r;
    dp = vector<vi>(n+1, vi(k+1, -1));
    cout << (f(0, 0) >= r ? "Missao completada com sucesso" : "Falha na missao") << endl;
}
int32_t main()
{
    IOS;
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}