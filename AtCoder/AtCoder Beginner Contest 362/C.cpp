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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int lim_int = 0, lim_sup = 0;
    for (auto &i : v) {
        cin >> i.first >> i.second;
        lim_int += i.first;
        lim_sup += i.second;
    }

    if (lim_int > 0 || lim_sup < 0) {
        cout << "No" << endl;
        return;
    }

    vector<int> x(n);
    int curr_s = 0;
    for (int i = 0; i < n; i++) {
        x[i] = v[i].first;
        curr_s += x[i];
    }

    int i = 0;
    while (curr_s != 0 && i < n) {
        int space = min(v[i].second - x[i], -curr_s);
        x[i] += space;
        curr_s += space;
        i++;
    }

    if (curr_s == 0) {
        cout << "Yes" << endl;
        for (auto i : x)
            cout << i << " ";
    } else {
        cout << "No" << endl;
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