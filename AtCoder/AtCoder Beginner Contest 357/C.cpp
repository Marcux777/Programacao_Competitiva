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

/*Problem Statement
For a non-negative integer K, we define a level-K carpet as follows:

A level-0 carpet is a 1×1 grid consisting of a single black cell.
For K>0, a level-K carpet is a 3^K×3^K grid.
When this grid is divided into nine 3^(K−1)×3^(K−1)blocks:
- The central block consists entirely of white cells.
- The other eight blocks are level-(K−1) carpets.
You are given a non-negative integer N.
Print a level-N carpet according to the specified format.*/

void f(int n, int x, int y)
{
    if (n == 0)
    {
        cout << (x == 0 && y == 0 ? "#" : ".");
        return;
    }
    int side = pow(3, n);
    int mid = side / 3;
    if (x >= mid && x < 2 * mid && y >= mid && y < 2 * mid)
    {
        cout << ".";
    }
    else
    {
        f(n - 1, x % mid, y % mid);
    }
}

void solve()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << "#" << endl;

    else
    {
        for (int i = 0; i < pow(3, n); i++)
        {
            for (int j = 0; j < pow(3, n); j++)
            {
                f(n, i, j);
            }
            cout << endl;
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