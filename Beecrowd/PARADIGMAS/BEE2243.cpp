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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__), cerr << endl

bool pode(const vi &tam, int mid) {
    int necessario = mid * (mid + 1) / 2;
    int atual = 0;
    for (auto i : tam) {
        atual += min(i, mid);
        if (atual >= necessario) return true;
    }
    return atual >= necessario;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v) cin >> i;

    vi left(n+2, 0), right(n+2, 0);
    for(int i = 1; i <= n; i++) left[i] = min(left[i-1]+1, v[i-1]);
    for(int i = n; i >= 1; i--) right[i] = min(right[i+1]+1, v[i-1]);
    

    int r = min(*max_element(all(v)), (n + 1) / 2 + 1);
    int l = 1;
    int ans = 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        bool found = false;
        for (int c = 1; c <= n; ++c) {
            if (left[c] >= mid && right[c] >= mid) {
                if (c - (mid - 1) >= 1 && c + (mid - 1) <= n) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

signed main() {
    IOS;
    int tt;
    tt = 1;
    while (tt--)
        solve();
    return 0;
}