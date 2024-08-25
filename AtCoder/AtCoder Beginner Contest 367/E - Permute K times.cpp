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

vector<int> f(const vector<int>& x, int p) {
    if (p == 0) {
        vector<int> result(x.size());
        for (int i = 0; i < x.size(); ++i) {
            result[i] = i;
        }
        return result;
    } else if (p % 2 == 0) {
        vector<int> y = f(x, p / 2);
        vector<int> result(y.size());
        for (int i = 0; i < y.size(); ++i) {
            result[i] = y[y[i]];
        }
        return result;
    } else {
        vector<int> y = f(x, p - 1);
        vector<int> result(y.size());
        for (int i = 0; i < y.size(); ++i) {
            result[i] = y[x[i]];
        }
        return result;
    }
}

void solve()
{
    int n, k; cin >> n >> k;

    vi x(n), a(n);
    for(auto &i : x) {
        cin >> i;
        i--;
    }
    for(auto &i : a) cin >> i;

    x = f(x, k);

    ostringstream oss;
    for (int i = 0; i < x.size(); ++i) {
        oss << a[x[i]];
        if (i < x.size() - 1) {
            oss << " ";
        }
    }

    cout << oss.str() << endl;

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