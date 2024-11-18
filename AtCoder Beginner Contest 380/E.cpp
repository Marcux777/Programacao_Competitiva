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


class DSU {
public:
    vi parent, rank, color, countCor;
    int n;
    DSU(int n) : parent(n + 1), rank(n + 1, 1), color(n + 1), countCor(n + 1, 0), n(n) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            color[i] = i;      
            countCor[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
            color[i] = color[parent[i]];
        }
        return parent[i];
    }

    int unite(int u, int v) {
        if (u == v) return u;

        if (rank[u] < rank[v]) {
            swap(u, v);
        }

        parent[v] = u;
        rank[u] += rank[v];
        return u;
    }

    void re_pinto(int x, int c) {
    int rx = find(x);
    int old_c = color[rx];

    if (color[rx] != c) {
        countCor[old_c] -= rank[rx];
        color[rx] = c;
        countCor[c] += rank[rx];
    }

    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int ru = find(u);

        for (int v : {u - 1, u + 1}) {
            if (v >= 1 && v <= n) {
                int rv = find(v);
                if (ru != rv && color[rv] == old_c) {
                    countCor[old_c] -= rank[rv];
                    countCor[c] += rank[rv];
                    color[rv] = c;
                    ru = unite(ru, rv);
                    q.push(v);
                }
            }
        }
    }
}

};

void solve()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    rep(i, 0, n+1) dsu.countCor[i] = 1;
    while(q--){
        string t;
        cin >> t;
        if(t == "1"){
            int x, c; cin >> x >> c;
            dsu.re_pinto(x, c);
        }else{
            int x; cin >> x;
            cout << dsu.countCor[x] << endl;
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