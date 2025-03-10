/*
~~ Alguma parte/frase foda de um livro/mangá para dar sorte ~~

Uma vez eu gritei, gradualmente, perdi minha voz.
Uma vez eu chorei, gradualmente, perdi minhas lágrimas.
Uma vez eu sofri, gradualmente, me tornei capaz de suportar tudo.
Uma vez me alegrei, gradualmente, me tornei indiferente ao mundo.
E agora, tudo o que me resta é um rosto sem expressão,
meu olhar é tão firme quanto um monólito,
apenas a perseverança permanece no meu coração.
Este sou eu, um personagem insignificante,
Fang Yuan — A Perseverança.

*/
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
    int n, x;
    cin >> n >> x;
    vi v(n), a(n), c(n);

    rep(i, 0, n) cin >> v[i] >> a[i] >> c[i];

    vii t1, t2, t3;
    rep(i, 0, n)
    { 
        if (v[i] == 1)
            t1.pb({c[i], a[i]});
        if (v[i] == 2)
            t2.pb({c[i], a[i]});
        if (v[i] == 3)
            t3.pb({c[i], a[i]});
    }
    auto cmp = [&](vii &v)
    {
        vi dp(x + 1, 0);
        dp[0] = 0;
        for (auto &[c, a] : v)
        {
            for (int j = x; j >= c; j--)
            {
                dp[j] = max(dp[j], dp[j - c] + a);
            }
        }
        return dp;
    };

    vi dp1 = cmp(t1), dp2 = cmp(t2), dp3 = cmp(t3);
    auto min_cust = [&](vi &dp, int m)
    {
        ll ans = LINF;
        rep (c, 0, x+1)
        {
            if (dp[c] >= m)
                ans = min(ans, (ll)c);
        }
        return ans;
    };

    int lo = 0LL, hi = min({dp1[x], dp2[x], dp3[x]}), ans = 0LL;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int c1 = sz(t1) ? min_cust(dp1, mid) : (mid == 0LL ? 0LL : INF);
        int c2 = sz(t2) ? min_cust(dp2, mid) : (mid == 0LL ? 0LL : INF);
        int c3 = sz(t3) ? min_cust(dp3, mid) : (mid == 0LL ? 0LL : INF);

        if (c1 != INF && c2 != INF && c3 != INF && (c1 + c2 + c3) <= x)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
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