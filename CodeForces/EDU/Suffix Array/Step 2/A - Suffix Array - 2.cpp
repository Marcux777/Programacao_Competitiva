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

// algoritmo de Karkkainen e Sanders
vector<int> suffix_array(const string& s) {
    int n = s.size() + 1;
    vector<int> sa(n), rank(n);

    // Inicialização para strings de tamanho 1
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k <<= 1) {
        // Ordena os sufixos com base nos primeiros 2*k caracteres
        sort(sa.begin(), sa.end(), [&](int i, int j) {
            if (rank[i] != rank[j]) {
                return rank[i] < rank[j];
            }
            int ri = i + k < n ? rank[i + k] : -1;
            int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        });

        // Calcula o novo rank
        vector<int> new_rank(n);
        new_rank[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            new_rank[sa[i]] = new_rank[sa[i - 1]];
            if (rank[sa[i]] != rank[sa[i - 1]] || (sa[i] + k >= n && sa[i - 1] + k < n) ||
                (sa[i] + k < n && sa[i - 1] + k >= n) ||
                (sa[i] + k < n && sa[i - 1] + k < n && rank[sa[i] + k] != rank[sa[i - 1] + k])) {
                new_rank[sa[i]]++;
            }
        }
        rank = new_rank;

        // Se todos os sufixos tiverem ranks diferentes, o Suffix Array está completo
        if (rank[sa[n - 1]] == n - 1) {
            break;
        }
    }

    return sa;
}

void solve()
{
    string s;
    cin >> s;
    vi ans = suffix_array(s);

    for(auto i : ans) cout << i << " ";
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