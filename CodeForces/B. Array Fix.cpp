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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__), cerr << endl

bool isOrdened(vector<int>&v){
    for(int i = 0; i < v.size()-1; i++){
        if(v[i] > v[i+1]) return false;
    }
    return true;
}
void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    while(!isOrdened(v)){
        for(int i = 0; i < n-1; i++){
            if(v[i] >= v[i+1]){
                auto it = v[i];
                
            }
        }
    }


}
int32_t main()
{
    IOS;
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}