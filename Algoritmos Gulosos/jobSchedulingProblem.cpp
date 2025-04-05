#include <iostream>
#include <vector>
#include <algorithm>

struct Tarefa {
    int id, deadline, lucro;
};

bool comparar(Tarefa a, Tarefa b) {
    return a.lucro > b.lucro;
}

int escalonamentoDeTarefas(std::vector<Tarefa>& tarefas) {
    std::sort(tarefas.begin(), tarefas.end(), comparar);
    
    int maxDeadline = 0;
    for (const auto& t : tarefas) 
        maxDeadline = std::max(maxDeadline, t.deadline);

    std::vector<int> agenda(maxDeadline + 1, -1);
    int lucroTotal = 0;

    for (const auto& t : tarefas) {
        for (int j = t.deadline; j > 0; j--) {
            if (agenda[j] == -1) {
                agenda[j] = t.id;
                lucroTotal += t.lucro;
                break;
            }
        }
    }
    return lucroTotal;
}

int main() {
    std::vector<Tarefa> tarefas = {{1, 2, 100}, {2, 1, 50}, {3, 2, 200}, {4, 1, 30}};
    
    std::cout << "Lucro máximo: " << escalonamentoDeTarefas(tarefas) << std::endl;
    return 0;
}
