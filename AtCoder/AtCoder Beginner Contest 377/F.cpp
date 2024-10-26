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

set<pii> st;

bool is_safe(vii &a, int x, int y) {
    for (auto &p : a) {
        int px = p.first, py = p.second;
        if (px == x || py == y || (px + py == x + y) || (px - py == x - y)) {
            return false;
        }
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    set<int> row, col, diag1, diag2;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        row.insert(a);
        col.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    int sobrando = (n - row.size()) * (n - col.size());

    int a = 0;
    for(auto i : diag1){
        int ci = max(1, i - n);
        int cm = min(n, i - 1);

        rep(j, ci, cm+1){
            int x = i - j;
            if(x >= 1 && x <= n)
                if(row.count(j) && col.count(x))
                    a++;
        }
    }

    for(auto i : diag2){
        int ci = max(1, 1 + i);
        int cm = min(n, n + i);
        rep(j, ci, cm+1){
            int x = j - i;
            if(x >= 1 && x <= n)
                if(row.count(j) && col.count(x))
                    b++;
        }
    }




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