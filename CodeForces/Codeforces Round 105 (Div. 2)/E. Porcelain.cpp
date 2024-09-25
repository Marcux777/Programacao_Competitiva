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
    int n, m;
    cin >> n >> m;
    vvi mat(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mat[i].resize(x);
        for (int j = 0; j < x; j++)
            cin >> mat[i][j];
    }
    // Initialize the dp table with -1 and set the starting point dp[0][0] to 0
    vvi dp(n + 1, vi(m + 1, -1));
    dp[0][0] = 0;

    // Iterate over each row of the matrix
    for (int i = 0; i < n; i++)
    {
        int tam = mat[i].size(); // Get the size of the current row
        vi prefix(tam + 1, 0), suffix(tam + 1, 0); // Initialize prefix and suffix sums

        // Calculate prefix sums
        for (int j = 0; j < tam; j++)
        {
            prefix[j + 1] = prefix[j] + mat[i][j];
            suffix[j + 1] = suffix[j] + mat[i][tam - j - 1];
        }

        vi max_damage(tam + 1, 0); // Initialize max_damage array

        // Calculate the maximum damage for each possible number of elements taken
        for (int k = 0; k <= tam; k++)
        {
            for (int l = 0; l <= k; l++)
            {
                int left = l; // Number of elements taken from the left
                int right = k - l; // Number of elements taken from the right
                max_damage[k] = max(max_damage[k], prefix[left] + suffix[right]);
            }
        }

        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] == -1) // Skip if the current state is not reachable
                continue;
            for (int k = 0; k <= min(tam, m - j); k++) // Iterate over possible number of elements to take
                dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + max_damage[k]);
        }
    }

    int result = 0;
    for (int i = 0; i <= m; i++)
        result = max(result, dp[n][i]);
    cout << result << endl;
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