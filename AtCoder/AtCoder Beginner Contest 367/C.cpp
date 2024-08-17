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

void f(int pos, int N, int K, vi& R, vi& current_sequence, int current_sum, vvi& results) {
    if (pos == N) {
        if (current_sum % K == 0) {
            results.push_back(current_sequence);
        }
        return;
    }

    for (int i = 1; i <= R[pos]; ++i) {
        current_sequence[pos] = i;
        f(pos + 1, N, K, R, current_sequence, current_sum + i, results);
    }
}

void solve()
{
    int n, k; cin >> n >> k;
    vi r(n), seq(n);
    for(auto &i : r) cin >> i;

    vvi ans;

    f(0, n, k, r, seq, 0, ans);

    sort(ans.begin(), ans.end());

    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
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