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

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    // é de ladim papai!!
    int ladim = sqrt(n);
    bool ok = true;
    if (n != ladim * ladim)
    {
        ok = false;
    }
    vector<vector<char>> m(ladim, vector<char>(ladim));
    for (int i = 0; i < ladim; ++i) {
        for (int j = 0; j < ladim; ++j) {
            m[i][j] = s[i * ladim + j];
        }
    }
    for (int i = 0; i < ladim && ok; ++i) {
        if (m[0][i] != '1' || m[ladim - 1][i] != '1') {
            ok = false;
        }
        if (m[i][0] != '1' || m[i][ladim - 1] != '1') {
            ok = false;
        }
    }
    for (int i = 1; i < ladim - 1 && ok; ++i) {
        for (int j = 1; j < ladim - 1; ++j) {
            if (m[i][j] != '0') {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
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