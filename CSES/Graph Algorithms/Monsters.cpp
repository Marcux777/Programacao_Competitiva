/*
~~ Alguma parte/frase foda de um livro/mangá para dar sorte ~~

Uma vez eu gritei, gradualmente, perdi minha voz.
Uma vez eu chorei, gradualmente, perdi minhas lágrimas.
Uma vez eu sofri, gradualmente, me tornei capaz de suportar tudo.
Uma vez me alegrei, gradualmente, me tornei indiferente ao mundo.
E agora, tudo o que me resta é um rosto sem expressão,
meu olhar é tão firme quanto um monólito,
apenas a perseverança permanece no meu coração.
Este sou eu, um personagem insignificante,
Fang Yuan — A Perseverança.

*/
#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i] << (i + 1 == v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define TXTIO                           \
    freopen("entrada.in", "r", stdin);\
    freopen("saida.out", "w", stdout)
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
const int LOGN = 21;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    pii A;
    vvi dist(n, vi(m, INF));
    queue<pii> mq;
    rep(i, 0, n) rep(j, 0, m) {
        if (s[i][j] == 'M') {
            dist[i][j] = 0;
            mq.push({i, j});
        } else if (s[i][j] == 'A') {
            A = {i, j};
        }
    }
    vii d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!mq.empty()) {
        auto [x, y] = mq.front();
        mq.pop();
        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 or nx >= n or ny < 0 or ny >= m or s[nx][ny] == '#')
                continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    queue<pii> pq;
    pq.push(A);

    vvi dist2(n, vi(m, INF));
    vector<vector<pair<pii, char>>> parent(n, vector<pair<pii, char>>(m, {{-1, -1}, ' '}));
    dist2[A.f][A.s] = 0;
    while (sz(pq)) {
        auto [x, y] = pq.front();
        pq.pop();
        for (auto& [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 or nx >= n or ny < 0 or ny >= m or s[nx][ny] == '#')
                continue;
            if (dist2[nx][ny] > dist2[x][y] + 1 and dist[nx][ny] > dist2[x][y] + 1) {
                dist2[nx][ny] = dist2[x][y] + 1;
                char moveChar;
                if (dx == -1 and dy == 0)
                    moveChar = 'U';
                else if (dx == 1 and dy == 0)
                    moveChar = 'D';
                else if (dx == 0 and dy == -1)
                    moveChar = 'L';
                else // dx == 0 and dy == 1
                    moveChar = 'R';
                parent[nx][ny] = {{x, y}, moveChar};
                pq.push({nx, ny});
            }
        }
    }

    pii exitCell = {-1, -1};
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                if (dist2[i][j] < INF) {
                    exitCell = {i, j};
                    break;
                }
            }
        }
        if (exitCell.f != -1) break;
    }

    string ans;
    if (exitCell.f == -1) {
        cout << "NO" << endl;
    } else {
        for (pii cur = exitCell; cur != A;) {
            auto [par, moveChar] = parent[cur.f][cur.s];
            ans.pb(moveChar);
            cur = par;
        }
        reverse(all(ans));
        cout << "YES" << endl << sz(ans) << endl << ans << endl;
    }
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    while (tt --> 0)
        solve();
    return 0;
}
