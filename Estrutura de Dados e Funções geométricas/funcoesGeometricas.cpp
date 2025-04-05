#include <iostream>
#include <cmath>

struct Ponto {
    double x, y;
    
    Ponto(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    
    void exibir() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

// 🔹 Função para calcular a distância entre dois pontos
double distanciaEntrePontos(const Ponto& p1, const Ponto& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

// 🔹 Distância entre um ponto e uma reta (Ax + By + C = 0)
double distanciaPontoReta(const Ponto& p, double A, double B, double C) {
    return std::abs(A * p.x + B * p.y + C) / std::sqrt(A * A + B * B);
}

// 🔹 Área da seção transversal de um triângulo formado por 3 pontos
double areaSeccaoTransversal(const Ponto& A, const Ponto& B, const Ponto& C) {
    return 0.5 * std::abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

int main() {
    Ponto p1(1, 2), p2(4, 6);
    std::cout << "Distância entre os pontos: " << distanciaEntrePontos(p1, p2) << std::endl;

    Ponto p3(3, 5);
    double A = 1, B = -1, C = -1; // Reta: x - y - 1 = 0
    std::cout << "Distância do ponto à reta: " << distanciaPontoReta(p3, A, B, C) << std::endl;

    Ponto A1(1, 1), B1(4, 1), C1(2, 5);
    std::cout << "Área da seção transversal: " << areaSeccaoTransversal(A1, B1, C1) << std::endl;

    return 0;
}
