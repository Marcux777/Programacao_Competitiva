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
Fang Yuan — A Perseverança.

*/
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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;

static const int MAXN = 1000000000;
static vi L;

void genLucky(int x)
{
    if (x > MAXN) return;
    if (x != 0) L.pb(x);
    genLucky(x * 10 + 4);
    genLucky(x * 10 + 7);
}

void solve()
{
    // 1) Gera e ordena os lucky numbers até 1e9
    genLucky(0);
    sort(all(L));

    // 2) Acrescenta sentinelas
    L.insert(L.begin(), 0LL);          // Sentinela < 1
    L.pb(10000000000LL);       // Sentinela > 1e9

    // 3) Lê os dados de entrada
    int pl, pr, vl, vr;
    int k;
    cin >> pl >> pr >> vl >> vr >> k;

    // 4) Quantidade total de pares (p, v)
    int totalPares = (pr - pl + 1) * (vr - vl + 1);

    // 5) Vamos somar em total a quantidade de (p,v)
    //    cujo intervalo [min(p,v), max(p,v)] contém exatamente k lucky numbers
    __int128 total = 0; // usando __int128 para evitar overflow

    // 6) Loop pelos blocos de k lucky consecutivos: L[i..i+k-1]
    // Tamanho do array L = m+2. Precisamos i+k-1 < sz(L).
    // => i <= sz(L) - k - 1
    for (int i = 1; i + k - 1 < sz(L); i++)
    {
        // Xmin..Xmax e Ymin..Ymax definem o retângulo (x,y)
        // cujo [x,y] (com x <= y) contém exatamente L[i..i+k-1]
        int Xmin = L[i - 1] + 1;   // x > L[i-1]
        int Xmax = L[i];          // x <= L[i]
        int Ymin = L[i + k - 1];  // y >= L[i+k-1]
        int Ymax = L[i + k] - 1;  // y < L[i+k]

        // Se não houver intervalo válido, pula
        if (Xmin > Xmax || Ymin > Ymax) continue;

        // Agora dividimos a contagem em:
        //   1) x < y, x em [pl, pr], y em [vl, vr]
        //   2) x < y, x em [vl, vr], y em [pl, pr]
        //   3) x = y, ambos em [pl, pr] ∩ [vl, vr]

        // 7.1) x < y, x em [pl, pr], y em [vl, vr]
        {
            int Ax = max(Xmin, pl);
            int Bx = min(Xmax, pr);
            int Ay = max(Ymin, vl);
            int By = min(Ymax, vr);

            // Precisamos Ax <= x <= Bx, Ay <= y <= By, e x < y
            if (Ax <= Bx && Ay <= By)
            {
                // Soma = ∑_{x=Ax..Bx} [# de y em [Ay..By] com y > x]
                //      = ∑_{x=Ax..Bx} [max(0, By - max(Ay, x+1) + 1)]
                __int128 partialSum = 0;
                // x não pode exceder By-1 se queremos y > x
                int Xlimit = min(Bx, By - 1);
                if (Xlimit < Ax) {
                    partialSum = 0;
                } else {
                    int Xsplit = Ay - 1;
                
                    // Parte 1: x <= Xsplit
                    int M1 = min(Xlimit, Xsplit);
                    __int128 S1 = 0;
                    if (M1 >= Ax) {
                        S1 = ((__int128)(M1 - Ax + 1) * (By - Ay + 1));
                    }
                
                    // Parte 2: x >= Xsplit + 1
                    int M2 = max(Ax, Xsplit + 1);
                    __int128 S2 = 0;
                    if (M2 <= Xlimit) {
                        int countX = (Xlimit - M2 + 1);
                        __int128 sumX = ((__int128)(M2 + Xlimit) * countX) / 2;
                        S2 = ((__int128)countX * By - sumX);
                    }
                
                    partialSum = S1 + S2;
                }
                total += partialSum;
            }
        }

        // 7.2) x < y, x em [vl, vr], y em [pl, pr]
        {
            int Ax = max(Xmin, vl);
            int Bx = min(Xmax, vr);
            int Ay = max(Ymin, pl);
            int By = min(Ymax, pr);

            if (Ax <= Bx && Ay <= By)
            {
                __int128 partialSum = 0;
                // x não pode exceder By-1 se queremos y > x
                int Xlimit = min(Bx, By - 1);
                if (Xlimit < Ax) {
                    partialSum = 0;
                } else {
                    int Xsplit = Ay - 1;
                
                    // Parte 1: x <= Xsplit
                    int M1 = min(Xlimit, Xsplit);
                    __int128 S1 = 0;
                    if (M1 >= Ax) {
                        S1 = ((__int128)(M1 - Ax + 1) * (By - Ay + 1));
                    }
                
                    // Parte 2: x >= Xsplit + 1
                    int M2 = max(Ax, Xsplit + 1);
                    __int128 S2 = 0;
                    if (M2 <= Xlimit) {
                        int countX = (Xlimit - M2 + 1);
                        __int128 sumX = ((__int128)(M2 + Xlimit) * countX) / 2;
                        S2 = ((__int128)countX * By - sumX);
                    }
                
                    partialSum = S1 + S2;
                }
                total += partialSum;
            }
        }

        // 7.3) x = y (interseção), conta uma única vez
        {
            // x = y em [Xmin..Xmax] e [Ymin..Ymax] => interseção
            int A = max(Xmin, Ymin);
            int B = min(Xmax, Ymax);
            if (A <= B)
            {
                // Agora x=y em [A..B], e x precisa estar em [pl,pr] e em [vl,vr] simultaneamente
                int C = max(pl, vl);
                int D = min(pr, vr);

                int Lfinal = max(A, C);
                int Rfinal = min(B, D);
                if (Lfinal <= Rfinal)
                {
                    // Cada x (igual a y) em [Lfinal..Rfinal] gera 1 par
                    total += (Rfinal - Lfinal + 1);
                }
            }
        }
    }

    long double prob = (long double)total / (long double)totalPares;

    // 8) Imprime resultado com precisão
    cout << fixed << setprecision(12) << prob << endl;
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
