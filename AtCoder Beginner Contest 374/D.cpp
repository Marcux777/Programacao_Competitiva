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

struct Segment {
    ld x1, y1, x2, y2;
    ld length;
};

ld distance(ld x1, ld y1, ld x2, ld y2) {
    return sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solve() {
    int N;
    ld S, T;
    cin >> N >> S >> T;

    vector<Segment> segments(N);
    for (int i = 0; i < N; ++i) {
        ld A, B, C, D;
        cin >> A >> B >> C >> D;
        segments[i] = {A, B, C, D, distance(A, B, C, D)};
    }

    vi perm(N);
    iota(all(perm), 0);

    ld min_time = LDBL_MAX;

    do {
        int total_combinations = 1 << N;
        for (int mask = 0; mask < total_combinations; ++mask) {
            ld curr_time = 0.0;
            ld curr_x = 0.0, curr_y = 0.0;
            for (int idx = 0; idx < N; ++idx) {
                int i = perm[idx];
                bool start_from_first = (mask >> idx) & 1;
                ld start_x = start_from_first ? segments[i].x1 : segments[i].x2;
                ld start_y = start_from_first ? segments[i].y1 : segments[i].y2;
                ld end_x = start_from_first ? segments[i].x2 : segments[i].x1;
                ld end_y = start_from_first ? segments[i].y2 : segments[i].y1;

                ld move_time = distance(curr_x, curr_y, start_x, start_y) / S;
                curr_time += move_time;

                ld print_time = segments[i].length / T;
                curr_time += print_time;

                curr_x = end_x;
                curr_y = end_y;
            }

            if (curr_time < min_time) {
                min_time = curr_time;
            }
        }
    } while (next_permutation(all(perm)));

    cout << fixed << setprecision(20) << min_time << endl;
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