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
Fang Yuan — A Perseverança.

*/
#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
vector<ordered_set> segTree;
vector<int> arr;
int n;


void init() {
    segTree.assign(4*n, ordered_set());
}

void insert_val(int node, int start, int end, int idx, int val){
    segTree[node].insert(val);
    if(start == end) return;
    int mid = (start + end) / 2;
    if(idx <= mid) insert_val(node*2, start, mid, idx, val);
    else insert_val(node*2+1, mid+1, end, idx, val);
}

int query(int node, int start, int end, int l, int r, int k) {
    if (start > r || end < l) return 0;
    if (l <= start && end <= r) {
        return (int)segTree[node].size() - segTree[node].order_of_key(k);
    }
    int mid = (start + end) / 2;
    return query(node*2, start, mid, l, r, k) +
           query(node*2+1, mid+1, end, l, r, k);
}

void update_tree(int node, int start, int end, int idx, int old_val, int new_val) {
    segTree[node].erase(old_val);
    segTree[node].insert(new_val);
    
    if (start == end) return;
    int mid = (start + end) / 2;
    if (idx <= mid)
        update_tree(node*2, start, mid, idx, old_val, new_val);
    else
        update_tree(node*2+1, mid+1, end, idx, old_val, new_val);
}

void solve()
{
    cin >> n;
    arr.resize(n);
    rep(i, 0, n) cin >> arr[i];
    init();

    rep(i, 0, n) insert_val(1, 0, n-1, i, arr[i]);

    int q; cin >> q;
    while(q--){
        int op, l, r, k; cin >> op;
        if(!op){
            cin >> l >> r >> k;
            l--, r--;
            cout << query(1, 0, n-1, l, r, k) << endl;
        }
        else{
            cin >> l >> r;
            l--;
            update_tree(1, 0, n-1, l, arr[l], r);
            arr[l] = r;
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