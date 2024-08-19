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
    int n; cin >> n;
    vd v(3);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[x-1]++;
    }

    vvvd dp(n + 1, vvd(n + 1, vd(n + 1, 0.0)));

    for (int i = 0; i <= v[2]; i++) {
        for (int j = 0; j <= v[1] + v[2]; j++) {
            for (int k = 0; k <= v[0] + v[1] + v[2]; k++) {
                if (i == 0 && j == 0 && k == 0) continue;
                if (i + j + k > n) continue;

                double total = i + j + k;
                dp[i][j][k] = n / total;

                if (k > 0) dp[i][j][k] += (k / total) * dp[i][j][k - 1];
                if (j > 0) dp[i][j][k] += (j / total) * dp[i][j - 1][k + 1];
                if (i > 0) dp[i][j][k] += (i / total) * dp[i - 1][j + 1][k];
            }
        }
    }

    cout << fixed << setprecision(15) << dp[v[2]][v[1]][v[0]] << endl;
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