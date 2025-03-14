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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i] << (i + 1 == v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

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
const int MAX = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
const int LOGN = 21;
// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};


namespace seg {
	// Se tiver uma seg de max, da pra descobrir em O(log(n))
	// o primeiro e ultimo elemento >= val numa range:

	// primeira posicao >= val em [a, b] (ou -1 se nao tem)
	int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_left(a, b, val, 2*p, l, m);
		if (x != -1) return x;
		return get_left(a, b, val, 2*p+1, m+1, r);
	}

	// ultima posicao >= val em [a, b] (ou -1 se nao tem)
	int get_right(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_right(a, b, val, 2*p+1, m+1, r);
		if (x != -1) return x;
		return get_right(a, b, val, 2*p, l, m);
	}

	// Se tiver uma seg de soma sobre um array nao negativo v, da pra
	// descobrir em O(log(n)) o maior j tal que v[i]+v[i+1]+...+v[j-1] < val
	int lower_bound(int i, ll& val, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (r < i) return n;
		if (i <= l and seg[p] < val) {
			val -= seg[p];
			return n;
		}
		if (l == r) return l;
		int m = (l+r)/2;
		int x = lower_bound(i, val, 2*p, l, m);
		if (x != n) return x;
		return lower_bound(i, val, 2*p+1, m+1, r);
	}
}

void solve()
{
    int n, q; cin >> n >> q;
    int a[n];
    for(auto &i : a) cin >> i;
    seg::build(n, a);
    while(q--){
        int t; cin >> t;
        if(t==1){
            int k, u; cin >> k >> u;
            int diff = seg::query(k-1, k-1);
            seg::update(k-1, k-1, u-diff);
            //seg::update(k-1, k-1, u);
        }else{
            int a, b; cin >> a >> b;
            cout << seg::query(a-1, b-1) << endl;
        }
    }
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    while (tt --> 0)
        solve();
    return 0;
}
