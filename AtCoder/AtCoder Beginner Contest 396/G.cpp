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

/**
 * @brief Resolve o problema de encontrar o custo mínimo para organizar linhas.
 *
 * Esta função:
 * 1. Lê uma grade de tamanho h×w composta por caracteres '0' e '1'.
 * 2. Usa programação dinâmica para calcular o custo de diferentes arranjos.
 * 3. dp[j][mask] representa o número de linhas que têm j bits definidos como 1 e correspondem ao padrão de bits 'mask'.
 * 4. Para cada padrão de bits, calcula o custo total onde o custo para cada linha é min(número de 1s, número de 0s).
 * 5. Retorna o custo mínimo possível entre todos os padrões de bits.
 *
 * Complexidade de Tempo: O(h + w * 2^w)
 * Complexidade de Espaço: O(w * 2^w)
 */
void solve()
{
    // Leitura das dimensões da grade
    int h, w; cin >> h >> w;
    // Inicializa a tabela de DP: dp[i][mask] = número de linhas com i bits 1 no padrão mask
    vvi dp((w+1), vi(1<<w, 0));
    // Inicializa a resposta com um valor muito grande
    int ans = LINF;
    // Leitura da grade
    vector<string> grid(h);
    rep(i, 0, h) {
        cin >> grid[i];
    }

    // Processa as linhas da grade, contando quantas linhas correspondem a cada padrão de bits
    rep(i, 0, h) {
        int mask = 0;
        rep(j, 0, w) {
            // Se o caractere for '1', ativa o bit correspondente no mask
            if (grid[i][j] == '1') {
                mask |= (1 << j);
            }
        }
        // Incrementa a contagem para este padrão com 0 bits alterados
        dp[0][mask]++;
    }

    // Preenche a tabela DP
    rep(i, 0, w) {
        for (int j = i; j >= 0; j--) {
            rep(bit, 0, (1 << w)) {
                // Altera o bit na posição i e atualiza dp
                dp[j + 1][bit ^ (1 << i)] += dp[j][bit];
            }
        }
    }

    // Encontra o custo mínimo entre todas as configurações possíveis
    rep(bit, 0, (1 << w)) {
        int res = 0;
        rep(i, 0, w + 1) {
            res += min(i, w - i) * dp[i][bit];
        }
        ans = min(ans, res);
    }

    cout << ans << endl;
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
