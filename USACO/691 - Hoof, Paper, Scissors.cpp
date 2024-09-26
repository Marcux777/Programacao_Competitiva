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

int f(const vector<char>& s, char c, char next) {
    int n = s.size();
    vector<int> prefix(n + 1, 0);
    vector<int> suffixWins(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + (s[i] == 'H' && c == 'P') + 
                                             (s[i] == 'P' && c == 'S') + 
                                             (s[i] == 'S' && c == 'H');
    }

    for (int i = n - 1; i >= 0; --i) {
        suffixWins[i] = suffixWins[i + 1] + (s[i] == 'H' && next == 'P') + 
                                           (s[i] == 'P' && next == 'S') + 
                                           (s[i] == 'S' && next == 'H');
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, prefix[i] + suffixWins[i]);
    }

    return ans;
}

void solve(ifstream &cin, ofstream& cout)
{
    int n; cin >> n;
    vector<char> s(n);
    for(auto &i : s) cin >> i;

    int ans = max({
        f(s, 'H', 'P'),
        f(s, 'H', 'S'),
        f(s, 'P', 'H'),
        f(s, 'P', 'S'),
        f(s, 'S', 'P'),
        f(s, 'S', 'H'),
        
    });
    cout << ans << endl;
    
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    ifstream in("hps.in");
    ofstream out("hps.out");
    while (tt--)
        solve(in, out);

    in.close();
    out.close();
    return 0;
}