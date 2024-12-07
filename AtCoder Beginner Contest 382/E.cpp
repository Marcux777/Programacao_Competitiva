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
    int n, x; cin >> n >> x;
    vd p(n);
    for(auto &i : p) {
        cin >> i;
        i /= 100;
    }
    vd prob(n + 1, 1);
    prob[0] = 1.0;
    double mu = 0.0;
    rep(i, 0, n){
        vd temp(n+1, 0);
        rep(k, 0, i+1){
            // ñ é rara
            temp[k] += prob[k] * (1.0 - p[i]);
            // é rara
            temp[k+1] += prob[k] * p[i];
        }
        prob = temp;
    }
    rep(i, 1, n+1) mu += i * prob[i];

    double acc_prob = 0.0, expect = 0.0;
    int mx = max(100LL, static_cast<int>(x / mu * 5));
    vd dp(x + mx + n + 1, 0.0);
    
    dp[0] = 1.0;
    rep(i, 1, mx){
        vd temp(sz(dp), 0.0);
        rep(j, 0, sz(dp)){
            if(dp[j] > 0.0){
                rep(k, 0, n+1)
                    if(prob[k] > 0.0)
                        temp[j + k] += dp[j] * prob[k];
            }
        }
        double prob_x = 0.0;
        rep (j, x, temp.size()+1) 
            prob_x += temp[j];

        // Calcular P(T = t)
        double pt = prob_x - acc_prob;
        acc_prob += pt;
        expect += i * pt;

        dp = temp;

        if (acc_prob >= 0.999999) {
            break;
        }
    }
    cout << fixed << setprecision(16);
    cout << expect << endl;
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