#include <bits/stdc++.h>

using namespace std;

#define int long long int
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


int f(int n, int m, vector<int>& A) {
    sort(A.begin(), A.end());
    int low = 0, high = A.back();

    while (low <= high) {
        int x = (low + high) / 2;
        int total_subsidy = 0;
        for (int cost : A) {
            total_subsidy += min(x, cost);
        }

        if (total_subsidy <= m) {
            low = x + 1;
        } else {
            high = x - 1;
        }
    }

    if (low <= A.back()) {
        return low - 1;
    } else {
        return -1;
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = f(n, m, v);

    if(ans != -1) cout << ans << endl;
    else cout << "infinite" << endl;
    
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