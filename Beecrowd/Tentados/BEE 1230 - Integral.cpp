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

struct point{
    int x, f;
};

bool comp(point a, point b){
    return a.x < b.x;
}


void solve()
{
    
    int n, m, y;
    while(cin >> n >> m >> y){
        vector<point> s(m);
        for(int i = 0; i < m; i++)
            cin >> s[i].x >> s[i].f;

        sort(s.begin(), s.end(), comp);

        vi f(n+1, -1);
        for(auto &i : s)
            f[i.x] = i.f;
        
        for(int i = 1; i < n; i++)
            if(f[i] == -1){
                f[i] = (f[i-1] + f[i+1])/2;
            }

        int area = 0;
        for(int i = 0; i < n; i++)
            area += (f[i] + f[i+1])/2;

        if(area == y){
            cout << "S";
            for(int i = 1; i < n; i++)
                if(f[i]!=-1) cout << " " << f[i];
            cout << endl;
        }else{
            cout << "N" << endl;
        }
    }

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