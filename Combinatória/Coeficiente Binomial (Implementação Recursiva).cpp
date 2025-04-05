#include <iostream>

using namespace std;

long long binomial_recursivo(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomial_recursivo(n - 1, k - 1) + binomial_recursivo(n - 1, k);
}

int main() {
    int n = 5, k = 2;
    cout << "C(" << n << ", " << k << ") = " << binomial_recursivo(n, k) << endl;
    return 0;
}
