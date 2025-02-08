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

void fft(vector<complex<double>>& a, bool invert) {
    int n = (int)a.size();

    // 1) Rearranjo "bit-reversal"
    for(int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        for(; j & bit; bit >>= 1){
            j ^= bit;
        }
        j ^= bit;
        if(i < j) {
            swap(a[i], a[j]);
        }
    }

    // 2) Iterações em blocos (tamanhos 2, 4, 8, ...)
    for(int len = 2; len <= n; len <<= 1) {
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        complex<double> wlen( cos(ang), sin(ang) );
        for(int i = 0; i < n; i += len) {
            complex<double> w(1.0, 0.0);
            for(int j = 0; j < len/2; j++){
                complex<double> u = a[i + j];
                complex<double> v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }

    // 3) Se for FFT inversa, dividimos por n
    if(invert) {
        for(int i = 0; i < n; i++){
            a[i] /= n;
        }
    }
}


// Convolução real (usando FFT) - aqui os valores de entrada são não-negativos
// Mas a saída pode ser grande, então usamos "long long" para armazenar.
vector<long long> convolve(const vector<long long>& A, const vector<long long>& B) {
    // 1) Determinar tamanho final
    int nA = A.size(), nB = B.size();
    int nRes = nA + nB - 1;

    // 2) Escolher n (potência de 2) que acomode nRes
    int nFFT = 1;
    while(nFFT < nRes) nFFT <<= 1;

    // 3) Copiar A e B em vetores de complex<double>
    vector<complex<double>> FA(nFFT), FB(nFFT);
    for(int i = 0; i < nA; i++){
        FA[i] = complex<double>( (double)A[i], 0.0 );
    }
    for(int i = 0; i < nB; i++){
        FB[i] = complex<double>( (double)B[i], 0.0 );
    }

    // 4) FFT em FA e FB
    fft(FA, false);
    fft(FB, false);

    // 5) Multiplicar no domínio da frequência
    for(int i = 0; i < nFFT; i++){
        FA[i] *= FB[i];
    }

    // 6) Inversa em FA
    fft(FA, true);

    // 7) Arredondar para obter os valores inteiros
    vector<long long> res(nFFT);
    for(int i = 0; i < nFFT; i++){
        long long val = (long long) llround(FA[i].real());
        res[i] = val;
    }

    // 8) Cortar tamanho para nRes
    res.resize(nRes);
    return res;
}

void solve()
{
    int n; cin >> n;
    vi f(1000005,0);
    vi s(n);
    rep(i, 0, n){
        cin >> s[i];
        f[s[i]] = 1LL;
    }
    vi g = convolve(f, f);
    int ans = 0LL;
    rep(i, 0, 1000005+1){
        if(f[i] == 1){
            ans+= (g[2*i] - 1) / 2;
        }
    }
    cout << ans << endl;
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
