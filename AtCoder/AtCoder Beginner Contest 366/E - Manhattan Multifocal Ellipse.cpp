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
const int MAXN = 4e6 + 5;
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

const int DMAX = 1e6 + 1;

const int M = 1e6;

vector<int> calculate_prefix_sums(const vector<int>& z, int n) {
    vector<int> c(4 * M + 1, 0);
    for (int v : z) {
        c[v]++;
    }

    vector<int> s(4 * M + 1, 0);
    s[0] = accumulate(z.begin(), z.end(), 0LL);
    int diff = -n;
    for (int i = 0; i < 4 * M; ++i) {
        diff += 2 * c[i];
        s[i + 1] = s[i] + diff;
    }
    return s;
}

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        x[i] += 2 * M;
        y[i] += 2 * M;
    }

    vector<int> sx = calculate_prefix_sums(x, n);
    vector<int> sy = calculate_prefix_sums(y, n);

    vector<int> cy(d + 1, 0);
    for (int v : sy) {
        if (v <= d) {
            cy[v]++;
        }
    }

    vector<int> a(d + 2, 0);
    for (int i = 0; i <= d; ++i) {
        a[i + 1] = a[i] + cy[i];
    }

    int ans = 0;
    for (int v : sx) {
        if (v <= d) {
            ans += a[d - v + 1];
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