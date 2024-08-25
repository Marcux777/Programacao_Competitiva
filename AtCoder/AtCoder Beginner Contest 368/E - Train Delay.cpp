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

struct Train {
    int departure_city;
    int arrival_city;
    int departure_time;
    int arrival_time;
};

void solve() {
    int n, m, x0;
    cin >> n >> m >> x0;
    vvi abst(m, vi(4));
    viii events;

    for(int i = 0; i < m; i++){
        cin >> abst[i][0] >> abst[i][1] >> abst[i][2] >> abst[i][3];
        events.pb({abst[i][2], {2, i}});
        events.pb({abst[i][3], {1, i}});
    }

    vi x(m, 0), arr(n+1, 0);
    sor(events);

    for (const auto& event : events) {
        int t = event.first;
        int k = event.second.first;
        int i = event.second.second;
        int A = abst[i][0];
        int B = abst[i][1];
        int S = abst[i][2];
        int T = abst[i][3];

        if (k == 1) {
            arr[B] = max(arr[B], T + x[i]);
        } else {
            x[i] = (i > 0) ? max(0LL, arr[A] - S) : x0;
        }
    }

    for (int i = 1; i < m; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;

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