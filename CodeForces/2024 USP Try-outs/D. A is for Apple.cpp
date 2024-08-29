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
    ld x, y, z;
    ld tx, ty, tz, raio;
    cin >> x >> y >> z;
    cin >> tx >> ty >> tz >> raio;

    ld l = 0.0, r = min({x, y, z})/2.0;
    ld tol = 1e-15;
    int it = 0;
    tx = max(tx, x - tx);
    ty = max(ty, y - ty);
    tz = max(tz, z - tz);

    while(r - l > tol && it < 1000){
        it++;
        ld R = (l + r) / 2.0;
        ld distance = ((R - tx)*(R - tx) + (R - ty)*(R - ty) + (R - tz)*(R - tz));

        if (distance >= (raio + R) * (raio + R)) {
            l = R;
        }else{
            r = R;
        }
    }
    cout << fixed << setprecision(15);
    cout << l << endl;
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