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
Fang Yuan — A Perseverança.

*/
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

vector<vector<int>> tree;
vector<int> arr;
int n;

// Constrói a Merge Sort Tree
void build(int node, int start, int end) {
    if(start == end) {
        tree[node].push_back(arr[start]);
        return;
    }
    
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    
    // Merge dos vetores ordenados dos filhos
    merge(tree[2*node].begin(), tree[2*node].end(),
          tree[2*node+1].begin(), tree[2*node+1].end(),
          back_inserter(tree[node]));
}

// Retorna quantidade de elementos > k no range [l,r]
int query(int node, int start, int end, int l, int r, int k) {
    if(start > r || end < l)
        return 0;
        
    if(l <= start && end <= r) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
    }
    
    int mid = (start + end) / 2;
    return query(2*node, start, mid, l, r, k) + 
           query(2*node+1, mid+1, end, l, r, k);
}

void solve()
{
    int n; cin >> n;
    arr.resize(n);
    tree.resize(4*n);
    rep(i, 0, n) cin >> arr[i];
    build(1, 0, n-1);
    int q; cin >> q;
    while(q--){
        int l, r, k; cin >> l >> r >> k;
        l--, r--;
        cout << query(1, 0, n-1, l, r, k) << endl;
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