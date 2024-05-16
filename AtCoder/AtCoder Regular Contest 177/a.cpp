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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int sum = a + b * 5 + c * 10 + d * 50 + e * 100 + f * 500;
    int sumValue = 0;
    bool compra = true;
    int n;
    cin >> n;
    vector<int> cost(n);
    for (auto &i : cost)
    {
        cin >> i;
        sumValue += i;
    }
    cout << sumValue << endl;
    int remaining = sumValue;
    sum -= remaining;
    remaining -= 
    remaining %= 500;
    e -= remaining / 100;
    remaining %= 100;
    d -= remaining / 50;
    remaining %= 50;
    c -= remaining / 10;
    remaining %= 10;
    b -= remaining / 5;
    remaining %= 5;
    a -= remaining;
    if (sum < 0 || a < 0 || b < 0 || c < 0 || d < 0 || e < 0 || f < 0)
        compra = false;
    if (compra)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int32_t main()
{
    IOS;
    int tt = 1;
    while (tt--)
        solve();
    return 0;
}