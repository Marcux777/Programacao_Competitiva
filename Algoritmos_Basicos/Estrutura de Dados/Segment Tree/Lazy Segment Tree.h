template <typename T>
class SegmentTree {
public:
    SegmentTree(int n) : n(n), t(4 * n), lazy(4 * n) {}

    void build(const vector<T>& a, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }

    void push(int v) {
        t[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int l, int r, T addend, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r)
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(l, min(r, tm), addend, v * 2, tl, tm);
            update(max(l, tm + 1), r, addend, v * 2 + 1, tm + 1, tr);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }

    T query(int l, int r, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r)
            return 0;
        if (l == tl && tr == r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(query(l, min(r, tm), v * 2, tl, tm),
                   query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
    }

private:
    int n;
    std::vector<T> t;
    std::vector<T> lazy;
};