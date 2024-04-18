#include <bits/stdc++.h>

using namespace std;

#define int long long int

class Segtree
{
public:
    Segtree(vector<int> &arr) : n(arr.size())
    {
        tree.resize(4 * n);
        build_tree(arr, 0, n - 1, 1); // Note: Root node is at index 1
    }

    int query(int left, int right)
    {
        return query_util(0, n - 1, left, right, 1);
    }

    void update(int index, int value)
    {
        update_util(0, n - 1, index, value, 1);
    }

private:
    int n; // Size of the input array
    std::vector<int> tree;

    void build_tree(const vector<int> &arr, int start, int end, int node)
    {
        if (start == end)
        { // Leaf node
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;

            // Build left and right subtrees recursively
            build_tree(arr, start, mid, 2 * node);
            build_tree(arr, mid + 1, end, 2 * node + 1);

            // Calculate sum of left and right subtrees
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query_util(int start, int end, int query_left, int query_right, int node)
    {
        if (start > query_right || end < query_left)
        {
            return 0; // No overlap
        }
        if (start >= query_left && end <= query_right)
        {
            return tree[node]; // Complete overlap
        }

        int mid = (start + end) / 2;
        int left_sum = query_util(start, mid, query_left, query_right, 2 * node);
        int right_sum = query_util(mid + 1, end, query_left, query_right, 2 * node + 1);
        return left_sum + right_sum;
    }

    void update_util(int start, int end, int index, int value, int node)
    {
        if (start == end)
        { // Leaf node
            tree[node] = value;
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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
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
            cout << tree.query(l, r-1) << endl;
        }
    }
}