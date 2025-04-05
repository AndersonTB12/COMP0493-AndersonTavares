#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    double valor, peso;
};

bool comparar(Item a, Item b) {
    return (a.valor / a.peso) > (b.valor / b.peso);
}

double mochilaFracionaria(std::vector<Item>& itens, double capacidade) {
    std::sort(itens.begin(), itens.end(), comparar);

    double valorTotal = 0.0;
    for (const auto& item : itens) {
        if (capacidade >= item.peso) {
            capacidade -= item.peso;
            valorTotal += item.valor;
        } else {
            valorTotal += item.valor * (capacidade / item.peso);
            break;
        }
    }
    return valorTotal;
}

int main() {
    std::vector<Item> itens = {{60, 10}, {100, 20}, {120, 30}};
    double capacidade = 50;

    std::cout << "Valor máximo da mochila: " << mochilaFracionaria(itens, capacidade) << std::endl;
    return 0;
}
