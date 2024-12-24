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

bool nah_ih_win(vvi &a, const vector<array<int, 3>>& req, int mid){
    for(auto &[r, op, c] : req){
        if(op == 0){
            if((a[mid][r] >= c)){
                return false;
            }
        }
        else{
            if((a[mid][r] <= c)){
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vvi a(n, vi(k)), prefix(n, vi(k));
    
    rep(i, 0, n)
        rep(j, 0, k)
            cin >> a[i][j];
    
    rep(j, 0, k){
        prefix[0][j] = a[0][j];
        rep(i, 1, n)
            prefix[i][j] = prefix[i-1][j] | a[i][j];
    }

    while(q--) {
        int m;
        cin >> m;
        int ans = -1;
        
        vector<array<int, 3>> req(m);
        rep(i, 0, m) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            req[i] = {r, (o == '<' ? 0 : 1), c};
        }
        
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nah_ih_win(prefix, req, mid)){
                ans = mid + 1;
                r = mid - 1;
            }
            else{
                l = mid + 1;
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