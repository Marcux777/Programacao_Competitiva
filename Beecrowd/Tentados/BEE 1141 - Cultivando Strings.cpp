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


void solve()
{
    int n;
    while(cin >> n && n){
        vector<string> a;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            a.push_back(s);
        }
        sort(a.begin(), a.end(), [](string a, string b){
            return sz(a) < sz(b);
        });
        unordered_map<string, int> dp;
        int len = 1;
        for(auto i : a){
            dp[i] = 1;
            for(int j = 1; j < sz(i); j++){
                string pre = i.substr(0, j);
                string suf = i.substr(sz(i) - j);
                if(dp.count(pre))
                    dp[i] = max(dp[i], dp[pre]+1);
                if(dp.count(suf))
                    dp[i] = max(dp[i], dp[suf]+1);
            }
            len = max(len, dp[i]);
        }
        cout << len << endl;
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