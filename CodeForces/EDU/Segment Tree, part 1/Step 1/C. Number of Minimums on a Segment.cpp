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


class Segtree
{
public:
    Segtree(vector<int> &arr) : n(arr.size())
    {
        tree.resize(4 * n);
        build_tree(arr, 0, n - 1, 1); // Note: Root node is at index 1
    }

    pair<int, int> query(int left, int right)
    {
        return query_util(0, n - 1, left, right, 1);
    }

    void update(int index, int value)
    {
        update_util(0, n - 1, index, value, 1);
    }

private:
    int n;
    vector<pair<int, int>> tree;

    pair<int, int> merge(const auto &a, const auto &b){
        if(a.first < b.first) return a;
        if(b.first < a.first) return b;
        return {a.first, a.second+b.second};
    }

    void build_tree(const vector<int> &arr, int start, int end, int node)
    {
        if (start == end)
        { // Leaf node
            tree[node] = {arr[start], 1};
        }
        else
        {
            int mid = (start + end) / 2;

            // Build left and right subtrees recursively
            build_tree(arr, start, mid, 2 * node);
            build_tree(arr, mid + 1, end, 2 * node + 1);

            // Calculate sum of left and right subtrees
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query_util(int start, int end, int query_left, int query_right, int node)
    {
        if (start > query_right || end < query_left)
        {
            return {LINF, 0}; // No overlap
        }
        if (start >= query_left && end <= query_right)
        {
            return tree[node]; // Complete overlap
        }

        int mid = (start + end) / 2;
        auto left = query_util(start, mid, query_left, query_right, 2 * node);
        auto right = query_util(mid + 1, end, query_left, query_right, 2 * node + 1);
        return merge(left, right);
    }

    void update_util(int start, int end, int index, int value, int node)
    {
        if (start == end)
        { // Leaf node
            tree[node] = {value, 1};
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid)
        {
            update_util(start, mid, index, value, 2 * node);
        }
        else
        {
            update_util(mid + 1, end, index, value, 2 * node + 1);
        }

        // Update the current node based on its children
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (auto &i : v)
        cin >> i;
    Segtree tree(v);
    int op;
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            int pos, value;
            cin >> pos >> value;
            tree.update(pos, value);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            auto query = tree.query(l, r-1);
            cout << query.first << " " << query.second << endl;
        }
    }
}