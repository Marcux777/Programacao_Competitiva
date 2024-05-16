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

const int N = 3;
vvi A(N, vector<int>(N));

vvi line = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

int f(int turn, vector<int>& s, vector<int>& a) {
    for (auto l : line) {
        if (s[l[0]] == s[l[1]] && s[l[1]] == s[l[2]] && s[l[0]] == 1) {
            return INF;
        }
        if (s[l[0]] == s[l[1]] && s[l[1]] == s[l[2]] && s[l[0]] == 2) {
            return -INF;
        }
    }
    if (turn == N * N) {
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < N * N; ++i) {
            if (s[i] == 1) {
                s1 += a[i];
            } else {
                s2 += a[i];
            }
        }
        return s1 - s2;
    }
    if (turn % 2 == 0) {
        int ret = -INF;
        for (int i = 0; i < N * N; ++i) {
            if (s[i] == 0) {
                vi t = s;
                t[i] = 1;
                ret = max(ret, f(turn + 1, t, a));
            }
        }
        return ret;
    } else {
        int ret = INF;
        for (int i = 0; i < N * N; ++i) {
            if (s[i] == 0) {
                vi t = s;
                t[i] = 2;
                ret = min(ret, f(turn + 1, t, a));
            }
        }
        return ret;
    }
}

void solve()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    
    vi a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a.push_back(A[i][j]);
        }
    }

    vi s(N * N, 0);
    cout << (f(0, s, a) > 0 ? "Takahashi" : "Aoki") << endl;

}
int32_t main()
{
    IOS;
    int tt = 1;
    while (tt--)
        solve();
    return 0;
}