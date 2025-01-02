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
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    int n = sz(s);
    int m = sz(t);
    if (abs(m - n) > k)
    {
        cout << "No" << endl;
        return;
    }
    vi dp_prev(2 * k + 5, 0), dp_curr(2 * k + 5, 0);
    rep(j, 0, min(m, k) + 1)
        dp_prev[j] = j;

    

    rep(j, min(m, k) + 1, sz(dp_prev))
    {
        dp_prev[j] = INF;
    }
    rep(i, 1, n + 1)
    {
        int l = max(0LL, i - k);
        int r = min(m, i + k);

        fill(all(dp_curr), LINF);
        rep(j, l, r + 1)
        {
            int aux = j - (i - k);

            if (j == 0)
            {
                dp_curr[aux] = i;
                continue;
            }

            if (j - 1 >= 0 && (aux - 1) >= 0)
            {
                int cost = dp_prev[aux - 1];
                if (s[i - 1] != t[j - 1])
                    cost++;
                dp_curr[aux] = min(dp_curr[aux], cost);
            }   

            if ((j - 1) >= l && (aux - 1) > 0)
            {
                int cost = dp_curr[aux - 1] + 1;
                dp_curr[aux] = min(dp_curr[aux], cost);
            }

            if (aux < sz(dp_prev))
            {
                int cost = dp_prev[aux] + 1;
                dp_curr[aux] = min(dp_curr[aux], cost);
            }
        }
        dp_prev.swap(dp_curr);
    }
    int final_pos = m - (n - k);
    if (final_pos < 0 || final_pos >= sz(dp_prev))
    {
        cout << "No" << endl;
        return;
    }

    cout << (dp_prev[final_pos] <= k ? "Yes" : "No") << endl;
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