#include <iostream>

int prim(int n, const vector<vector<pair<int, int>>>& adj) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int total = 0;
    pq.emplace(0, 0); // {peso, vértice}

    while (!pq.empty()) {
        auto [peso, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total += peso;

        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                pq.emplace(w, v);
            }
        }
    }

    return total; // custo total da AGM
}