#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define all(v) v.begin(),v.end()
#define f first
#define s second
#define Unique(v) sort(all(v));v.erase(unique(all(v)),v.end());
#define sz(v) ((int)v.size())
#define sor(x) sort(all(x))
#define ft front()
#define bk back()
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<piii> viii;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
void dbg_out() { cerr << endl; }
//template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << ' ' << H; dbg_out(T...); }
//#define dbg(...) cerr<<"(" << #_VA_ARGS<<"):" , dbg_out(VA_ARGS_) , cerr << endl

double f(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve() {
    queue<int> pq;
    int n; cin >> n;
    vii a(n);
    vi points(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int mais_dist = -1;
    int id;
    for(int i = 0; i < n; ++i) {
        double maxDistance = 0;
        int id = -1;
        
        for(int j = 0; j < n; ++j) {
            if(i != j) {
                double distance = f(a[i].first, a[i].second, a[j].first, a[j].second);
                if(distance > maxDistance) {
                    maxDistance = distance;
                    id = j + 1;
                }
            }
        }
        cout << id << endl;
    }
    
}
int32_t main()
{
	IOS;
	int tt=1;
	while(tt--)
        solve();
	return 0;
}