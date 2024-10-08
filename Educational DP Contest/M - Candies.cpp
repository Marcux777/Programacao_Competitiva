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

void solve()
{
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (auto &i : v)
        cin >> i;

    vvi dp(n + 1, vi(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // Inicializa o vetor de soma prefixada com tamanho k+1 e todos os elementos como 0
        vi prefix_sum(k + 1, 0);

        // Define o primeiro elemento da soma prefixada como o valor correspondente da linha anterior da matriz dp
        prefix_sum[0] = dp[i - 1][0];

        // Calcula a soma prefixada para a linha anterior da matriz dp
        for (int j = 1; j <= k; j++)
        {
            // Soma o valor anterior da soma prefixada com o valor atual da linha anterior da matriz dp
            // Aplica o módulo para evitar estouro de inteiros
            prefix_sum[j] = (prefix_sum[j - 1] + dp[i - 1][j]) % mod;
        }

        // Calcula os valores da matriz dp para a criança atual
        for (int j = 0; j <= k; j++)
        {
            // Se a quantidade de doces j for menor ou igual ao número máximo de doces que a criança i-1 pode receber
            if (j <= v[i - 1])
            {
                // O valor dp[i][j] é igual à soma prefixada até j
                dp[i][j] = prefix_sum[j];
            }
            else
            {
                // Caso contrário, o valor dp[i][j] é a diferença entre a soma prefixada até j e a soma prefixada até (j - v[i-1] - 1)
                // Adiciona mod para garantir que o resultado seja positivo e aplica o módulo novamente
                dp[i][j] = (prefix_sum[j] - prefix_sum[j - v[i - 1] - 1] + mod) % mod;
            }
        }
    }
    cout << dp[n][k] << endl;
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