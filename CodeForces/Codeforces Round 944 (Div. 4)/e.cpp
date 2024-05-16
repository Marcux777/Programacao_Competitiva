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

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vi a(k + 1, 0), b(k + 1, 0);
    a[0] = 0;
    b[0] = 0;
    rep(i, 1, k + 1) cin >> a[i];
    rep(i, 1, k + 1) cin >> b[i];
    while (q--)
    {
        int d;
        cin >> d;
        int l = 0, r = k;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] > d)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (a[r] == d)
        {
            cout << b[r] << " ";
            continue;
        }
        int time = b[r] + (d - a[r]) * (b[r + 1] - b[r]) / (a[r + 1] - a[r]);

        cout << time << " ";
    }
}

int32_t main()
{
    IOS;
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}