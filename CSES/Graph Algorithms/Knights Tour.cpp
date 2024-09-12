#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <bits/stdc++.h>

using namespace std;

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

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, const vvi &mat) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && mat[x][y] == -1);
}

int countMoves(int x, int y, vector<vector<int>>& mat) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, mat)) {
            count++;
        }
    }
    return count;
}

bool dfs(int x, int y, int movei, vector<vector<int>>& mat, int& c) {
    if (movei == 64) return true;

    vector<pair<int, pair<int, int>>> moves;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (isValid(nx, ny, mat)) {
            int count = countMoves(nx, ny, mat);
            moves.push_back({count, {nx, ny}});
        }
    }

    sort(moves.begin(), moves.end());

    for (auto move : moves) {
        int nx = move.second.first;
        int ny = move.second.second;
        mat[nx][ny] = c++;
        if (dfs(nx, ny, movei + 1, mat, c)) return true;
        mat[nx][ny] = -1;
        c--;
    }

    return false;
}

void solve()
{
    vvi mat(8, vi(8, -1));
    int x, y;
    cin >> x >> y;
    x--, y--;
    int c = 1;
    mat[y][x] = 0;
    dfs(y, x, 1, mat, c);

    for (auto &i : mat)
    {
        for (auto &j : i)
            cout << j+1 << " ";
        cout << endl;
    }
}

int main()
{
    IOS;
    int tt;
    tt = 1;
    while (tt--)
        solve();
    return 0;
}