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

// mais elegante assim 

int prefixSum(int i, int k){
    // soma da PA 
    return (i * (2 * k + i - 1)) / 2;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int l = 1, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        int leftSum = prefixSum(mid, k);
        int rightSum = prefixSum(n, k) - leftSum;
        int x = abs(leftSum - rightSum);

        int x_left = abs(prefixSum(mid - 1, k) - (prefixSum(n, k) - prefixSum(mid - 1, k)));
        int x_right = abs(prefixSum(mid + 1, k) - (prefixSum(n, k) - prefixSum(mid + 1, k)));

        if (x <= x_left && x <= x_right)
            l = r = mid;
        else if (x_left < x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << abs(prefixSum(l, k) - (prefixSum(n, k) - prefixSum(l, k))) << endl;
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}