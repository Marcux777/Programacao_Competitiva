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

struct Intervalo
{
    int min, max;
};

void solve(ifstream &cin, ofstream &cout)
{
    int n;
    cin >> n;
    vector<Intervalo> v(n + 1);
    vector<string> tipo(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> tipo[i] >> v[i].min >> v[i].max;
    }

    // Encontra o primeiro trecho "none" e calcula o fluxo após ele
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (tipo[i] == "none")
        {
            k = i;
            break;
        }
    }

    ll fim_min = v[k].min;
    ll fim_max = v[k].max;

    for (int i = k + 1; i <= n; i++)
    {
        if (tipo[i] == "on")
        {
            fim_min += v[i].min;
            fim_max += v[i].max;
        }
        else if (tipo[i] == "off")
        {
            fim_min = max(fim_min - v[i].max, 0LL);
            fim_max = max(fim_max - v[i].min, 0LL);
        }
        else // tipo[i] == "none"
        {
            fim_min = max(fim_min, v[i].min);
            fim_max = min(fim_max, v[i].max);
        }
    }

    // Calcula o fluxo antes do primeiro trecho, percorrendo de trás para frente
    ll ini_min = fim_min;
    ll ini_max = fim_max;

    for (int i = n; i >= 1; i--)
    {
        if (tipo[i] == "on")
        {
            ini_min = max(ini_min - v[i].max, 0LL);
            ini_max = max(ini_max - v[i].min, 0LL);
        }
        else if (tipo[i] == "off")
        {
            ini_min += v[i].min;
            ini_max += v[i].max;
        }
        else
        {
            ini_min = max(ini_min, v[i].min);
            ini_max = min(ini_max, v[i].max);
        }
    }

    cout << ini_min << " " << ini_max << endl;
    cout << fim_min << " " << fim_max << endl;
}

int32_t main()
{
    IOS;
    ifstream in("traffic.in");
    ofstream out("traffic.out");
    int tt;
    tt = 1;
    while (tt--)
        solve(in, out);

    in.close();
    out.close();
    return 0;
}