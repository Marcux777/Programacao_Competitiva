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
int mod = 1e9 + 7;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

int pisano(int m) {
    int previous = 0;
    int current  = 1;
    int period = 0;

    for (int i = 0; i < m * m; ++i) {
        int temp = current;
        current = (previous + current) % m;
        previous = temp;

        if (previous == 0 && current == 1) {
            period = i + 1;
            break;
        }
    }

    return period;
}

void fastFib(int n, vi& v){
    if(n == 0){
        v[0] = 0;
        v[1] = 1;
        return;
    }
    fastFib(n/2, v);

    int a, b, c, d;
    a = v[0];
    b = v[1];
    c = 2*b - a;
    if(c < 0) c += mod;

    c = (a*c)%mod;
    d = (a*a + b*b)%mod;

    if(n%2 == 0){
        v[0] = c;
        v[1] = d;
    }
    else{
        v[0] = d;
        v[1] = c+d;
    }
}


void solve()
{
    int n, m;
    while(cin >> n >> m){
        mod = pisano(m);
        vi v(2);
        fastFib(n%mod, v);
        int a = v[0];
        v = vi(2);
        fastFib(a, v);
        cout << v[0] << endl;
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