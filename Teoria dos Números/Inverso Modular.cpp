#include <iostream>

// Algoritmo estendido de Euclides
int mdc_estendido(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = mdc_estendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

// Inverso modular
int inverso_modular(int a, int m) {
    int x, y;
    int g = mdc_estendido(a, m, x, y);
    if (g != 1) {
        throw std::invalid_argument("Inverso modular não existe (a e m não são coprimos)");
    }
    return (x % m + m) % m;
}