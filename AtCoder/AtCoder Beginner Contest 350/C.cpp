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

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> pos(N+1);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        pos[A[i]] = i+1;
    }

    vector<pair<int, int>> operations;
    for(int i = 1; i <= N; i++) {
        while(pos[i] != i) {
            int j = pos[i];
            swap(A[i-1], A[j-1]);
            swap(pos[i], pos[A[j-1]]);
            operations.push_back({i, j});
        }
    }

    cout << operations.size() << endl;
    for(auto& op : operations) {
        cout << op.first << " " << op.second << endl;
    }
}
int32_t main()
{
    IOS;
    int tt = 1;
    while (tt--)
        solve();
    return 0;
}
