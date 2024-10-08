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

struct music{
    int minuto;
    int duracao;
    int id;
    bool pulou;

    bool operator<(const music &a) const{
        return minuto < a.minuto;
    }
};

void solve()
{
    int n; cin >> n;

    vector<music> playlist(n);

    for(int i = 0; i < n; i++){
        int t, m, c;
        cin >> t >> m >> c;
        
        playlist[i] = {t, m, i+1, c==1};
    }
    sor(playlist);

    vi ans;
    int tempo = 0;
    queue<music> q;
    for(int i = 0; i < n; i++){
        while(q.size()){
            int s = (q.front().pulou ? q.front().minuto : max(tempo, q.front().minuto));
            if(s + q.front().duracao > playlist[i].minuto){
                break;
            }
            tempo = max(tempo, s + q.front().duracao);
            q.pop();
        }
        if(playlist[i].pulou && q.size()){
            ans.pb(q.front().id);
            q.front() = playlist[i];
        }
        else{
            q.push(playlist[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    
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