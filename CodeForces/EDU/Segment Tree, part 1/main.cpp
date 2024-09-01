#include <bits/stdc++.h>

using namespace std;

template <typename T, typename MergeOp = std::plus<T>>
class Segtree {
public:
    Segtree(const std::vector<T>& arr, MergeOp op = MergeOp(), T neutral = T{}) 
        : merge_op(op), neutral_element(neutral) {
        n = arr.size();
        tree.resize(4 * n);
        build_tree(arr, 0, n - 1, 1);
    }

    T query(int left, int right) {
        if (left < 0 || right >= n || left > right) {
            throw std::out_of_range("Invalid query range");
        }
        return query_util(0, n - 1, left, right, 1);
    }

    void update(int index, T value) {
        if (index < 0 || index >= n) {
            throw std::out_of_range("Invalid index");
        }
        update_util(0, n - 1, index, value, 1);
    }

private:
    int n;
    std::vector<T> tree;
    MergeOp merge_op;
    T neutral_element;

    T merge(T a, T b) {
        return merge_op(a, b);
    }

    void build_tree(const std::vector<T> &arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build_tree(arr, start, mid, 2 * node);
            build_tree(arr, mid + 1, end, 2 * node + 1);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    T query_util(int start, int end, int query_left, int query_right, int node) {
        if (start > query_right || end < query_left) {
            return neutral_element;
        }
        if (start >= query_left && end <= query_right) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        T left = query_util(start, mid, query_left, query_right, 2 * node);
        T right = query_util(mid + 1, end, query_left, query_right, 2 * node + 1);
        return merge(left, right);
    }

    void update_util(int start, int end, int index, T value, int node) {
        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid) {
            update_util(start, mid, index, value, 2 * node);
        } else {
            update_util(mid + 1, end, index, value, 2 * node + 1);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
 
    for (auto &i : v)
        cin >> i;

    auto sum_op = [](int a, int b){
        return a+b;
    };
    Segtree<int, decltype(sum_op)> tree(v, sum_op, 0);
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
            cout << tree.query(l, r-1) << endl;
        }
    }
}