#include <iostream>

// BIT: Fenwick Tree
struct FenwickTree {
    std::vector<int> bit;
    int n;

    FenwickTree(int tamanho) {
        n = tamanho;
        bit.assign(n + 1, 0);
    }

    // Atualiza posição i somando 'delta'
    void update(int i, int delta) {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    }

    // Soma dos elementos de 1 a i
    int query(int i) {
        int soma = 0;
        for (; i > 0; i -= i & -i)
            soma += bit[i];
        return soma;
    }

    // Soma de [l, r]
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    // Build a partir de vetor original
    void build(const std::vector<int>& arr) {
        for (int i = 1; i <= n; ++i)
            update(i, arr[i - 1]);
    }
};
