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
#define dbg(...) cerr << "(" << __VA_ARGS__ << "):", dbg_out(__VA_ARGS__), cerr << endl

class Segment_tree{

    struct data{
        ll sum , pref , suff , best ;
        data(int _val){
            sum = _val ;
            pref = suff = best = (0 > _val ? 0 : _val);
        }
    };
    vector<data> tree ;

    public :
    Segment_tree(vector<int> &v, int n = 1e5){
        tree.assign(n*4,data(0)) ;
        build(v, 1,0,v.size()-1);
    }

    void currbest(){
        cout << tree[1].best << endl ;
    }

    void update(int node, int index , int st, int sp , int value){
        if(st > index || sp < index )  return ;
        if(st == sp){
            tree[node] = data(value) ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            update(lft,index,st,mid,value) ;
            update(rght,index,mid+1,sp,value) ;
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }

    void build(const vector<int> &v , int node , int st , int sp ){
        if(st == sp){
            tree[node] = data(v[st]) ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            build(v,lft,st,mid) ;
            build(v,rght,mid+1,sp) ;
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }

    data operation(data l , data r){
        data new_(0) ;

        new_.sum = l.sum + r.sum ;
        new_.suff = max(r.suff, l.suff + r.sum) ;
        new_.pref = max(l.pref , l.sum + r.pref) ;
        new_.best =  max({l.best,r.best, r.pref + l.suff}) ;

        return new_ ;
    }

};

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
 
    for (auto &i : v)
        cin >> i;
    Segment_tree tree(v);
    tree.currbest();
    while (m--)
    {
        int i, value;
        cin >> i >> value;
        tree.update(1, i,0, n-1, value);
        tree.currbest();
        
    }
}