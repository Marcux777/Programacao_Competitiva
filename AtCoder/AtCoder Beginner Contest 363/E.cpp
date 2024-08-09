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
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    const int M = 100010;
    int ans = H * W;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    vector<deque<pii>> q(M + 1);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q[A[i][j]].emplace_back(i, j);
            }
        }
    }

    for (int y = 1; y <= Y; ++y) {
        while (!q[y].empty()) {
            auto [i, j] = q[y].front();
            q[y].pop_front();
            if (sunk[i][j]) continue;
            ans--;
            sunk[i][j] = true;
            for (auto [di, dj] : vii{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < H && 0 <= nj && nj < W) {
                    q[max(y, A[ni][nj])].emplace_back(ni, nj);
                }
            }
        }
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