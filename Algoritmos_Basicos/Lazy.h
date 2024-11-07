#include <vector>

using namespace std;

class LazySegmentTree {
    vector<int> tree, lazy;
    int n;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l)
            return;
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[node * 2 + 1] += val;
                lazy[node * 2 + 2] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(node * 2 + 1, start, mid, l, r, val);
        updateRange(node * 2 + 2, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    int queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > end || start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        int left = queryRange(node * 2 + 1, start, mid, l, r);
        int right = queryRange(node * 2 + 2, mid + 1, end, l, r);
        return left + right;
    }

public:
    LazySegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void update(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};
