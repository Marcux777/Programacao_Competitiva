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

int result;
int D;

ll pow_int(ll base, int exp) {
    ll result = 1;
    while (exp--) {
        if (result > LINF / base) return LINF; // Check overflow
        result *= base;
    }
    return result;
}

vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

void dfs(int index, ll curr, ll d, int last_e) {
    if (d == 1) {
        result = min(result, curr);
        return;
    }
    if (index >= primes.size()) return;
    for(int e = 1; e <= last_e; e++) {
        if(d % (e +1) != 0) continue;
        if(curr > LINF / pow_int(primes[index], e)) break;
        ll next_n = curr * (ll)pow(primes[index], e);
        if(next_n > LINF) break;
        dfs(index +1, next_n, d / (e +1), e);
    }
}

void solve()
{
    cin >> D;
    if(D ==1){
        cout << 1 << endl;
        return;
    }
    result = LINF;
    dfs(0, 1, D, 60);
    if(result <= 1e18){
        cout << result << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int32_t main()
{
    int tt;
    tt = 1;
    while (tt--)
        solve();
    return 0;
}