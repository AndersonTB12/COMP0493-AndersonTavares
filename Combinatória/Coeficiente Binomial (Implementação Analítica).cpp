#include <iostream>

using namespace std;

long long fatorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

long long binomial_analitico(int n, int k) {
    if (k > n) return 0;
    return fatorial(n) / (fatorial(k) * fatorial(n - k));
}

int main() {
    int n = 5, k = 2;
    cout << "C(" << n << ", " << k << ") = " << binomial_analitico(n, k) << endl;
    return 0;
}
