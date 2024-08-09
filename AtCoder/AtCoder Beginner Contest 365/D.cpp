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
const int INF = 1e9;
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

int score(int x, int y) {
    return (x - y + 3) % 3 == 1 ? 1 : (x == y ? 0 : -INF);
}
void solve()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<vector<int>> dp(N + 1, vector<int>(3, -INF));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 0; i < N; ++i) {
        int y = (S[i] == 'R' ? 0 : (S[i] == 'P' ? 1 : 2));
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (k != j) {
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + score(k, y));
                }
            }
        }
    } 

    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
    
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