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

void solve(ifstream &cin, ofstream &cout)
{
    int n, m; cin >> n >> m;
    vii v(n), seg(m);
    for(auto &i : v) cin >> i.f >> i.s;

    for(auto &i : seg) cin >> i.f >> i.s;

    int ans = 0;
    int i = 0, j = 0;
    int v_pos = 0, seg_pos = 0;
    while (i < n && j < m) {
        int v_len = v[i].f - v_pos;
        int seg_len = seg[j].f - seg_pos;
        int min_len = min(v_len, seg_len);

        ans = max(ans, seg[j].s - v[i].s);

        v_pos += min_len;
        seg_pos += min_len;

        if (v_pos == v[i].f) {
            i++;
            v_pos = 0;
        }
        if (seg_pos == seg[j].f) {
            j++;
            seg_pos = 0;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    IOS;
    ifstream in("speeding.in");
    ofstream out("speeding.out");
    int tt;
    tt = 1;
    while (tt--)
        solve(in, out);

    in.close();
    out.close();
    return 0;
}