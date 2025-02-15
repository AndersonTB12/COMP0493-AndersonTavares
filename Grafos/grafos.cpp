#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class GrafoMatriz {
private:
    vector<vector<int>> matriz;
    int V; // Número de vértices

public:
    GrafoMatriz(int vertices) : V(vertices) {
        matriz.resize(V, vector<int>(V, 0));
    }

    void adicionarAresta(int u, int v) {
        matriz[u][v] = 1;
        matriz[v][u] = 1; // Grafo não-direcionado
    }

    void BFS(int inicio) {
        vector<bool> visitado(V, false);
        queue<int> fila;
        fila.push(inicio);
        visitado[inicio] = true;

        cout << "BFS (Matriz): ";
        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();
            cout << atual << " ";

            for (int i = 0; i < V; i++) {
                if (matriz[atual][i] == 1 && !visitado[i]) {
                    fila.push(i);
                    visitado[i] = true;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visitado) {
        visitado[v] = true;
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (matriz[v][i] == 1 && !visitado[i]) {
                DFSUtil(i, visitado);
            }
        }
    }

    void DFS(int inicio) {
        vector<bool> visitado(V, false);
        cout << "DFS (Matriz): ";
        DFSUtil(inicio, visitado);
        cout << endl;
    }
};

class GrafoLista {
private:
    vector<vector<int>> lista;
    int V;

public:
    GrafoLista(int vertices) : V(vertices) {
        lista.resize(V);
    }

    void adicionarAresta(int u, int v) {
        lista[u].push_back(v);
        lista[v].push_back(u); // Grafo não-direcionado
    }

    void BFS(int inicio) {
        vector<bool> visitado(V, false);
        queue<int> fila;
        fila.push(inicio);
        visitado[inicio] = true;

        cout << "BFS (Lista): ";
        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();
            cout << atual << " ";

            for (int vizinho : lista[atual]) {
                if (!visitado[vizinho]) {
                    fila.push(vizinho);
                    visitado[vizinho] = true;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int v, vector<bool>& visitado) {
        visitado[v] = true;
        cout << v << " ";

        for (int vizinho : lista[v]) {
            if (!visitado[vizinho]) {
                DFSUtil(vizinho, visitado);
            }
        }
    }

    void DFS(int inicio) {
        vector<bool> visitado(V, false);
        cout << "DFS (Lista): ";
        DFSUtil(inicio, visitado);
        cout << endl;
    }
};

int main() {
    int V = 5;

    // Grafo com Matriz de Adjacência
    GrafoMatriz grafoMatriz(V);
    grafoMatriz.adicionarAresta(0, 1);
    grafoMatriz.adicionarAresta(0, 2);
    grafoMatriz.adicionarAresta(1, 3);
    grafoMatriz.adicionarAresta(2, 3);
    grafoMatriz.adicionarAresta(3, 4);

    // Grafo com Lista de Adjacência
    GrafoLista grafoLista(V);
    grafoLista.adicionarAresta(0, 1);
    grafoLista.adicionarAresta(0, 2);
    grafoLista.adicionarAresta(1, 3);
    grafoLista.adicionarAresta(2, 3);
    grafoLista.adicionarAresta(3, 4);

    cout << "Matriz de Adjacência:" << endl;
    grafoMatriz.BFS(0);
    grafoMatriz.DFS(0);

    cout << "\nLista de Adjacência:" << endl;
    grafoLista.BFS(0);
    grafoLista.DFS(0);

    return 0;
}
