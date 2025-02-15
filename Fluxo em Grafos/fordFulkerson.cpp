#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

#define V 6  // Número de vértices

// Função para buscar um caminho aumentante usando DFS
bool dfs(int grafoResidual[V][V], int u, int t, vector<int>& parent, vector<bool>& visitado) {
    visitado[u] = true;
    if (u == t) return true;

    for (int v = 0; v < V; v++) {
        if (!visitado[v] && grafoResidual[u][v] > 0) {
            parent[v] = u;
            if (dfs(grafoResidual, v, t, parent, visitado)) return true;
        }
    }
    return false;
}

// Implementação do algoritmo de Ford-Fulkerson
int fordFulkerson(int grafo[V][V], int s, int t) {
    int grafoResidual[V][V];
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            grafoResidual[u][v] = grafo[u][v];

    vector<int> parent(V);
    int fluxoMaximo = 0;

    while (true) {
        vector<bool> visitado(V, false);
        if (!dfs(grafoResidual, s, t, parent, visitado)) break;

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

    cout << "Fluxo máximo (Ford-Fulkerson): " << fordFulkerson(grafo, 0, 5) << endl;
    return 0;
}
