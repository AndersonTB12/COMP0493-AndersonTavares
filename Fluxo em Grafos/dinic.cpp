#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define V 6

struct Grafo {
    vector<vector<int>> capacidade, adj;
    vector<int> nivel, ptr;

    Grafo(int n) {
        capacidade.assign(n, vector<int>(n, 0));
        adj.assign(n, vector<int>());
    }

    void adicionarAresta(int u, int v, int cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacidade[u][v] = cap;
    }

    bool bfs(int s, int t) {
        nivel.assign(V, -1);
        queue<int> q;
        q.push(s);
        nivel[s] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (nivel[v] == -1 && capacidade[u][v] > 0) {
                    nivel[v] = nivel[u] + 1;
                    q.push(v);
                }
            }
        }
        return nivel[t] != -1;
    }

    int dfs(int u, int t, int fluxo) {
        if (u == t) return fluxo;
        for (; ptr[u] < adj[u].size(); ptr[u]++) {
            int v = adj[u][ptr[u]];
            if (nivel[v] == nivel[u] + 1 && capacidade[u][v] > 0) {
                int fluxoMin = min(fluxo, capacidade[u][v]);
                int fluxoEnviado = dfs(v, t, fluxoMin);
                if (fluxoEnviado > 0) {
                    capacidade[u][v] -= fluxoEnviado;
                    capacidade[v][u] += fluxoEnviado;
                    return fluxoEnviado;
                }
            }
        }
        return 0;
    }

    int dinic(int s, int t) {
        int fluxoMaximo = 0;
        while (bfs(s, t)) {
            ptr.assign(V, 0);
            while (int fluxo = dfs(s, t, INT_MAX))
                fluxoMaximo += fluxo;
        }
        return fluxoMaximo;
    }
};

int main() {
    Grafo g(V);
    g.adicionarAresta(0, 1, 16);
    g.adicionarAresta(0, 2, 13);
    g.adicionarAresta(1, 3, 12);
    g.adicionarAresta(2, 3, 14);
    g.adicionarAresta(3, 5, 20);

    cout << "Fluxo máximo (Dinic): " << g.dinic(0, 5) << endl;
    return 0;
}
