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
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;

    vvi prefix_sum(n + 1, vi(26, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            prefix_sum[i][j] = prefix_sum[i-1][j];
        }
        prefix_sum[i][s[i-1] - 'a']++;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (r - l == 0)
        {
            cout << "Yes" << endl;
            continue;
        }

        if (s[l-1] != s[r-1])
        {
            cout << "Yes" << endl;
            continue;
        }

        vi freq(26, 0);
        for (int j = 0; j < 26; ++j)
        {
            freq[j] = (prefix_sum[r][j] - prefix_sum[l-1][j]>0);
        }

        int dist_cnt = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (freq[j] > 0)
            {
                dist_cnt++;
            }
        }

        if (dist_cnt >= 3)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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