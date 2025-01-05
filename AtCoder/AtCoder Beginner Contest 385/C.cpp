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

void solve()
{
    int n; 
    cin >> n; // Leia o número de elementos
    vi a(n); 
    for(auto &i : a) 
        cin >> i; // Leia os elementos no vetor 'a'
    
    map<int, vi> mp; 
    rep(i, 0, n)
        mp[a[i]].pb(i); // Mapeie cada elemento para seus índices no vetor

    int ans = 1; // Inicialize a resposta com 1
    for(auto &[h, ind] : mp){
        int size = sz(ind); // Obtenha o tamanho do vetor de índices
        if(size == 1){
            ans = max(ans, 1LL); // Se houver apenas um índice, o comprimento máximo da sequência é 1
            continue;
        }
        rep(i, 0, size){
            rep(j, i+1, size){
                int c = 2; // Comece com uma sequência de comprimento 2
                int nxt = ind[j] + ind[j] - ind[i]; // Calcule o próximo índice esperado na sequência
                while(binary_search(all(ind), nxt)){ // Verifique se o próximo índice existe no vetor de índices
                    c++; // Incremente o comprimento da sequência
                    nxt += ind[j] - ind[i]; // Atualize o próximo índice esperado
                }
                ans = max(ans, c); // Atualize a resposta com o comprimento máximo da sequência encontrada
            }
        }
    }
    cout << ans << endl; // Imprima a resposta
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