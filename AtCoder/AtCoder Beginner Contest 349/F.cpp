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
const int mod = 998244353;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl
vector<int> factor(int M)
{
    vector<int> res;
    int i = 2;
    while (i * i <= M)
    {
        if (M % i == 0)
        {
            int e = 1;
            while (M % i == 0)
            {
                M /= i;
                e *= i;
            }
            res.push_back(e);
        }
        i += 1;
    }
    if (M > 1)
        res.push_back(M);
    return res;
}
void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto &i : A)
        cin >> i;
    vector<int> dp(1 << N);
    dp[0] = 1;
    rep(mask, 1, 1 << N)
    {
        int lcm = 1;
        for (int i = 0; i < N; i++)
        {
            if ((mask >> i) & 1)
            {
                if (lcm == 1)
                    lcm = A[i];
                else
                    lcm = lcm * A[i] / __gcd(lcm, A[i]);
            }
        }
        if (lcm == M)
            dp[mask] = 1;
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask)
        {
            lcm = 1;
            for (int i = 0; i < N; i++)
            {
                if ((sub >> i) & 1)
                {
                    if (lcm == 1)
                        lcm = A[i];
                    else
                        lcm = lcm * A[i] / __gcd(lcm, A[i]);
                }
            }
            if (lcm == M)
                dp[mask] = (dp[mask] + dp[sub]) % mod;
        }
    }
    int ans = -1;
    if (M == 1)
        ans = 0;
    for (int mask = 0; mask < (1 << N); mask++)
    {
        int x = 0;
        for (int sub = 0; sub < (1 << N); sub++)
        {
            if ((mask & sub) == sub)
                x += dp[sub];
        }
        int p = -1;
        if ((N - __builtin_popcount(mask)) % 2 == 0)
            p = 1;
        ans = (ans + p * x) % mod;
    }
    cout << ans << endl;
}

int32_t main()
{
    IOS;
    int tt = 1;
    while (tt--)
        solve();
    return 0;
}
