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
    int n; cin >> n;
    vi v(n);
    for(auto &i : v) cin >> i;

    vi prefix(n+1, 0);
    int ans = 0;
    ans = prefix[1] = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] == 1){
            // Se o elemento atual for 1 (ímpar):
            // O número de subarrays ímpares terminando em i é igual ao 
            // número de subarrays pares até i-1 mais 1 (o próprio elemento v[i]).
            prefix[i+1] = i + 1 - prefix[i];
        } else {
            // Se o elemento atual for 0 (par):
            // O número de subarrays ímpares terminando em i é igual ao 
            // número de subarrays ímpares até i-1.
            prefix[i+1] = prefix[i];
        }
        ans += prefix[i+1];
    }
    cout << ans << endl;
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