#include <iostream>

long long binaryExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long base = 3, exp = 13, mod = 1e9 + 7;
    std::cout << "3^13 mod (10^9 + 7) = " << binaryExponentiation(base, exp, mod) << std::endl;
    return 0;
}
