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
const int MOD = 1e9 + 7;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

void FastDoubling(int n, int &a, int &b, int mod) {
    if (n == 0) {
        a = 0;
        b = 1 % mod;
        return;
    }
    int a1, b1;
    FastDoubling(n / 2, a1, b1, mod);
    int c = (a1 * ((2 * b1 % mod - a1 + mod) % mod)) % mod;
    int d = (a1 * a1 % mod + b1 * b1 % mod) % mod;
    if (n % 2 == 0) {
        a = c;
        b = d;
    } else {
        a = d;
        b = (c + d) % mod;
    }
}

int compute_S(int k) {
    if (k == 1) return 1;
    for (int i = 1; i <= 6 * k; ++i) {
        int a, b;
        FastDoubling(i, a, b, k);
        if (a % k == 0) {
            return i;
        }
    }
    return -1;
}

void solve() {
    int t;
    cin >> t;
    vii cases(t);
    set<int> uni;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        cases[i] = {n, k};
        uni.insert(k);
    }

    unordered_map<int, int> mp;
    for (int k : uni) 
        mp[k] = compute_S(k);

    for (auto &tc : cases) {
        int n = tc.f;
        int k = tc.s;
        int S = mp[k];
        int ans = (n % MOD) * (S % MOD) % MOD;
        cout << ans << endl;
    }
}
int32_t main()
{
    IOS;
    solve();
    return 0;
}