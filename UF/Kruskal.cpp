#include <iostream>

vector<tuple<int, int, int>> kruskal(int n, vector<tuple<int, int, int>> edges) {
    sort(edges.begin(), edges.end()); // ordena por peso
    UnionFind uf(n);
    vector<tuple<int, int, int>> mst;

    for (auto& [w, u, v] : edges) {
        if (uf.unite(u, v)) {
            mst.emplace_back(w, u, v);
        }
    }

    return mst; // árvore geradora mínima
}