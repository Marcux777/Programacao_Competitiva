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
#define M_PI 3.14159265358979323846



bool intersect(int a, int b, int c, int d)
{
    double a_rad = (a % 12) * M_PI / 6;
    double b_rad = (b % 12) * M_PI / 6;
    double c_rad = (c % 12) * M_PI / 6;
    double d_rad = (d % 12) * M_PI / 6;
    double ax = cos(a_rad), ay = sin(a_rad);
    double bx = cos(b_rad), by = sin(b_rad);
    double cx = cos(c_rad), cy = sin(c_rad);
    double dx = cos(d_rad), dy = sin(d_rad);
    double A1 = by - ay;
    double B1 = ax - bx;
    double C1 = A1 * ax + B1 * ay;
    double A2 = dy - cy;
    double B2 = cx - dx;
    double C2 = A2 * cx + B2 * cy;

    double det = A1 * B2 - A2 * B1;

    if (det == 0)
    {
        return false;
    }

    double x = (B2 * C1 - B1 * C2) / det;
    double y = (A1 * C2 - A2 * C1) / det;

    return x * x + y * y <= 1;
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (intersect(a, b, c, d))
        cout << "YES\n";
    else
        cout << "NO\n";
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