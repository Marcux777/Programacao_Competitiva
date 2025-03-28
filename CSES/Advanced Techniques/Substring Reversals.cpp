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
#define TXTIO                           \
    freopen("entrada.in", "r", stdin);\
    freopen("saida.out", "w", stdout)
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
const int LOGN = 21;

template <typename T = char>
class Treap {
    private:
        struct Node {
            Node *left, *right;
            int weight, size;
            T val;
            bool rev;

            Node(T v) : left(NULL), right(NULL), weight(rand()), size(1), val(v), rev(false) {}
        };

        Node *root;

        int size(Node *treap) { return treap ? treap->size : 0; }

        void push_down(Node* treap){
            if(treap && treap->rev){
                swap(treap->left, treap->right);
                if(treap->left) treap->left->rev ^= true;
                if(treap->right) treap->right->rev ^= true;
                treap->rev = false;
            }
        }

        void split(Node *treap, Node *&left, Node *&right, int val) {
            if (!treap) {
                left = right = NULL;
                return;
            }
            push_down(treap);

            if (size(treap->left) < val) {
                split(treap->right, treap->right, right, val - size(treap->left) - 1);
                left = treap;
            } else {
                split(treap->left, left, treap->left, val);
                right = treap;
            }
            treap->size = 1 + size(treap->left) + size(treap->right);
        }

        void merge(Node *&treap, Node *left, Node *right) {
            if (left == NULL) {
                treap = right;
                return;
            }
            if (right == NULL) {
                treap = left;
                return;
            }

            push_down(left);
            push_down(right);

            if (left->weight < right->weight) {
                merge(left->right, left->right, right);
                treap = left;
            } else {
                merge(right->left, left, right->left);
                treap = right;
            }
            treap->size = 1 + size(treap->left) + size(treap->right);
        }

        void to_string_helper(Node *node, string &result) {
            if (!node) return;
            push_down(node);
            to_string_helper(node->left, result);
            result.push_back(node->val);
            to_string_helper(node->right, result);
        }

    public:
        Treap() : root(NULL) {}

        void insert(int pos, T val) {
            Node *left, *right, *mid;
            split(root, left, right, pos);
            mid = new Node(val);
            merge(root, left, mid);
            merge(root, root, right);
        }

        void cut_and_paste(int l, int r, int pos) {
            if (l >= pos) {
                // cutting from right of paste position
                Node *left, *mid, *right;
                split(root, left, right, l);
                split(right, mid, right, r - l + 1);
                merge(root, left, right);
                merge(root, root, mid);
            } else {
                // cutting from left of paste position
                Node *left, *mid, *right, *remaining;
                split(root, left, right, l);
                split(right, mid, right, r - l + 1);
                split(left, left, remaining, pos - (r - l + 1) < 0 ? 0 : pos - (r - l + 1));
                merge(root, left, right);
                merge(root, root, mid);
            }
        }

        void add_string(const string &s) {
            for (char c : s) {
                insert(size(root), c);
            }
        }

        T get_at(int pos) {
            Node *curr = root;
            int left_size = size(curr->left);

            while (pos != left_size) {
                if (pos < left_size) {
                    curr = curr->left;
                    left_size = size(curr->left);
                } else {
                    pos -= left_size + 1;
                    curr = curr->right;
                    left_size = size(curr->left);
                }
            }

            return curr->val;
        }

        string to_string() {
            string result;
            to_string_helper(root, result);
            return result;
        }

        void reverse(int l, int r){
            Node *left, *mid, *right;
            split(root, left, right, l);
            split(right, mid, right, r - l + 1);
            mid->rev ^= true;
            merge(root, left, mid);
            merge(root, root, right);
        }
};


void solve()
{
    int n, m; cin >> n >> m;
    string s; cin >> s;
    Treap<char>treap;
    treap.add_string(s);

    while(m--){
        int l, r; cin >> l >> r;
        l--,r--;
        treap.reverse(l, r);
    }
    cout << treap.to_string() << endl;
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
