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


void solve()
{
    int n; cin >> n;
    vi x(n), y(n), a(n);

    for(auto &i : x) cin >> i;
    for(auto &i : y) cin >> i;

    iota(a.begin(), a.end(),1);
    int p = 0,  q = 0, cont = 0;
    do{
        bool ok = true;
        cont++;
        for(int i = 0; i < n && ok; i++)
            if(a[i] != x[i])
                ok = false;

        if(p == 0 && ok){
            p = cont;
        }
        
        ok = true;

        for(int i = 0; i < n && ok; i++)
            if(a[i] != y[i])
                ok = false;

        if(q == 0 && ok){q = cont;}

        if(p != 0 && q != 0) break;


    }while(next_permutation(a.begin(), a.end()));


    cout << abs(p - q) << endl;

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