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

class FenwickTree {
public:
    int n;
    vector<long long> tree;

    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int index, long long value) {
        for (++index; index <= n; index += index & -index)
            tree[index] += value;
    }

    // prefix sum[0..index)
    long long sum(int index) {
        long long result = 0;
        for (; index > 0; index -= index & -index)
            result += tree[index];
        return result;
    }

    // sum over [left, right)
    long long sum(int left, int right) {
        return sum(right) - sum(left);
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    vi a(n);
    for(auto &i :a) cin >> i;
    vi s(n+1);
    rep(i, 1, n+1)
        s[i] = (s[i-1] + a[i-1])%m;

    FenwickTree fenwick(m);
    int sum, ans;
    sum = ans = 0;
    rep(i, 0, n+1){
        ans += s[i] * i - sum + fenwick.sum(s[i] + 1, m)*m;
        sum += s[i];
        fenwick.add(s[i], 1);
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