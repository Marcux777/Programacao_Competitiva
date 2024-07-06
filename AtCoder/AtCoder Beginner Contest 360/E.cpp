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
const int mod = 998244353;
const int p = mod;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

int quikpower(int a, int b, int MOD=mod)
{
    int res = 1;
    a%=p;
	while(b){
		if(b&1){
			res*=a;
			res%=p;	
		}
		a*=a;
		a%=p;
		b/=2;
	}
	return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if(n == 1) {cout << 1 << endl; return;}
    vvi dp(k+1, vi(2));
    dp[0][0] = 1;
    for(int i=1;i<=k;i++){
		dp[i][0]=dp[i-1][0]*(((n-1)*(n-1)+1)%p)%p*quikpower(n*n,p-2)%p;
		dp[i][0]+=dp[i-1][1]*quikpower(n*n,p-2)%p*2%p*(n-1)%p;
		dp[i][0]%=p;
		dp[i][1]=(1-dp[i][0]+p)*quikpower(n-1,p-2)%p;
	}
	cout<<(dp[k][0]%p+dp[k][1]%p*(n+2)%p*(n-1)%p*quikpower(2,p-2)%p)%p;
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
