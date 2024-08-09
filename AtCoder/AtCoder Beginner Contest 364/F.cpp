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

typedef tuple<int, int, int> edge;

struct DSU
{
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y)
    {
        int xr = find(x), yr = find(y);
        if (xr == yr)
            return false;
        if (rank[xr] < rank[yr])
            swap(xr, yr);
        parent[yr] = xr;
        if (rank[xr] == rank[yr])
            rank[xr]++;
        return true;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<node> a(m + 1);

    for (int i = 1; i <= n; i++)
        fa[i] = top[i] = i;

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].x;
        for (int j = a[i].l; j < a[i].r; j++)
        {
            merge(j, j + 1);
            j = top[find(j)] - 1;
        }
    }

    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(find(i));
    if (st.size() > 1)
    {
        cout << "-1" << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
        fa[i] = top[i] = i;
    sort(a.begin() + 1, a.end());

    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        st.clear();
        for (int j = a[i].l; j < a[i].r; j++)
        {
            if (find(j) != find(j + 1))
                res += a[i].x;
            merge(j, j + 1);
            j = top[find(j)] - 1;
        }
        res += a[i].x;
    }

    cout << res << endl;
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