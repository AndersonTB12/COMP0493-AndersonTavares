#include <iostream>
#include <vector>
#include <climits>

int problemaDoTroco(std::vector<int>& moedas, int valor) {
    std::vector<int> dp(valor + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= valor; i++) {
        for (int moeda : moedas) {
            if (i >= moeda && dp[i - moeda] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - moeda] + 1);
            }
        }
    }
    return dp[valor] == INT_MAX ? -1 : dp[valor];
}

int main() {
    std::vector<int> moedas = {1, 3, 4};
    int valor = 6;

    int resultado = problemaDoTroco(moedas, valor);
    if (resultado == -1)
        std::cout << "Não é possível formar o valor dado." << std::endl;
    else
        std::cout << "Mínimo de moedas necessárias: " << resultado << std::endl;
    return 0;
}
