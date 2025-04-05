#include <iostream>

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // compressão de caminho
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;

        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }
};