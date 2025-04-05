#include <iostream>

struct SegmentTree {
    int n;
    std::vector<int> tree_sum, tree_min, tree_max;

    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree_sum.resize(4 * n);
        tree_min.resize(4 * n);
        tree_max.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int l, int r, const std::vector<int>& arr) {
        if (l == r) {
            tree_sum[node] = tree_min[node] = tree_max[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(2 * node, l, mid, arr);
            build(2 * node + 1, mid + 1, r, arr);
            tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
            tree_min[node] = std::min(tree_min[2 * node], tree_min[2 * node + 1]);
            tree_max[node] = std::max(tree_max[2 * node], tree_max[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree_sum[node] = tree_min[node] = tree_max[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid)
                update(2 * node, l, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, r, idx, val);

            tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
            tree_min[node] = std::min(tree_min[2 * node], tree_min[2 * node + 1]);
            tree_max[node] = std::max(tree_max[2 * node], tree_max[2 * node + 1]);
        }
    }

    int query_sum(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree_sum[node];
        int mid = (l + r) / 2;
        return query_sum(2 * node, l, mid, ql, qr) + query_sum(2 * node + 1, mid + 1, r, ql, qr);
    }

    int query_min(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MAX;
        if (ql <= l && r <= qr) return tree_min[node];
        int mid = (l + r) / 2;
        return std::min(query_min(2 * node, l, mid, ql, qr), query_min(2 * node + 1, mid + 1, r, ql, qr));
    }

    int query_max(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MIN;
        if (ql <= l && r <= qr) return tree_max[node];
        int mid = (l + r) / 2;
        return std::max(query_max(2 * node, l, mid, ql, qr), query_max(2 * node + 1, mid + 1, r, ql, qr));
    }

    // Wrappers para facilitar uso
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query_sum(int l, int r) {
        return query_sum(1, 0, n - 1, l, r);
    }

    int query_min(int l, int r) {
        return query_min(1, 0, n - 1, l, r);
    }

    int query_max(int l, int r) {
        return query_max(1, 0, n - 1, l, r);
    }
};
