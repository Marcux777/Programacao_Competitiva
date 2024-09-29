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

int extra_votes(vector<pii>& a, vector<int>& s, int l, int r, int x) {
    auto pos = lower_bound(a.begin() + l, a.begin() + r, make_pair(x, -1LL)) - a.begin();
    return (pos - l) * x - (s[pos] - s[l]);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for (auto &i : a) cin >> i;
    
    int V = k - accumulate(all(a), 0LL);
    
    if (m == n) {
        for (int i = 0; i < n; ++i) cout << 0 << " ";
        cout << endl;
        return;
    }
    
    vector<pii> b(n);
    for (int i = 0; i < n; ++i) b[i] = {a[i], i};
    sort(all(b));
    
    vi s(n + 1, 0);
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + b[i].first;
    
    vi ans(n, 0);
    
    for (int i = 0; i < n; ++i) {
        int ng = -1, ok = V + 1;
        while (ng + 1 < ok) {
            int mi = (ng + ok) / 2;
            int x = b[i].first + mi + 1;
            int v;
            if (i < n - m) {
                v = extra_votes(b, s, n - m, n, x);
            } else {
                v = (i - (n - m - 1)) * x - (s[i] - s[n - m - 1]);
                v += extra_votes(b, s, i + 1, n, x);
            }
            if (v > V - mi) {
                ok = mi;
            } else {
                ng = mi;
            }
        }
        ans[b[i].second] = ok <= V ? ok : -1;
    }
    
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;
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