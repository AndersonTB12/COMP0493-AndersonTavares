#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define V 6

bool bfs(int grafoResidual[V][V], int s, int t, vector<int>& parent) {
    vector<bool> visitado(V, false);
    queue<int> fila;
    fila.push(s);
    visitado[s] = true;
    parent[s] = -1;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (int v = 0; v < V; v++) {
            if (!visitado[v] && grafoResidual[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                fila.push(v);
                parent[v] = u;
                visitado[v] = true;
            }
        }
    }
    return false;
}

int edmondsKarp(int grafo[V][V], int s, int t) {
    int grafoResidual[V][V];
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            grafoResidual[u][v] = grafo[u][v];

    vector<int> parent(V);
    int fluxoMaximo = 0;

    while (bfs(grafoResidual, s, t, parent)) {
        int fluxo = INT_MAX;
        for (int v = t; v != s; v = parent[v])
            fluxo = min(fluxo, grafoResidual[parent[v]][v]);

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            grafoResidual[u][v] -= fluxo;
            grafoResidual[v][u] += fluxo;
        }

        fluxoMaximo += fluxo;
    }

    return fluxoMaximo;
}

int main() {
    int grafo[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "Fluxo máximo (Edmonds-Karp): " << edmondsKarp(grafo, 0, 5) << endl;
    return 0;
}
