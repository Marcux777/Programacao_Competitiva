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
    int n, q; cin >> n;
    vector<vector<vector<int>>> A(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            for (int z = 1; z <= n; ++z) {
                cin >> A[x][y][z];
            }
        }
    }   
    vector<vector<vector<int>>> prefix_sum(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            for (int z = 1; z <= n; ++z) {
                prefix_sum[x][y][z] = 
                    A[x][y][z] +
                    prefix_sum[x-1][y][z] + 
                    prefix_sum[x][y-1][z] +
                    prefix_sum[x][y][z-1] -
                    prefix_sum[x-1][y-1][z] -
                    prefix_sum[x-1][y][z-1] -
                    prefix_sum[x][y-1][z-1] +
                    prefix_sum[x-1][y-1][z-1];
            }
        }
    }
    cin >> q;
    while(q--){
        int Lxi, Rxi, Lyi, Ryi, Lzi, Rzi;
        cin >> Lxi >> Rxi >> Lyi >> Ryi >> Lzi >> Rzi;

        int ans = 
            prefix_sum[Rxi][Ryi][Rzi] -
            prefix_sum[Lxi-1][Ryi][Rzi] -
            prefix_sum[Rxi][Lyi-1][Rzi] -
            prefix_sum[Rxi][Ryi][Lzi-1] +
            prefix_sum[Lxi-1][Lyi-1][Rzi] +
            prefix_sum[Lxi-1][Ryi][Lzi-1] +
            prefix_sum[Rxi][Lyi-1][Lzi-1] -
            prefix_sum[Lxi-1][Lyi-1][Lzi-1];

        cout << ans << endl;
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