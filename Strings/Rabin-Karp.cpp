#include <iostream>

vector<int> RabinKarp(const string& text, const string& pattern, int base = 256, int mod = 1e9+7) {
    int n = text.size(), m = pattern.size();
    long long hpattern = 0, htext = 0, h = 1;
    vector<int> ocorrencias;

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % mod;

    for (int i = 0; i < m; i++) {
        hpattern = (base * hpattern + pattern[i]) % mod;
        htext = (base * htext + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hpattern == htext) {
            if (text.substr(i, m) == pattern)
                ocorrencias.push_back(i);
        }
        if (i < n - m) {
            htext = (base * (htext - text[i] * h % mod + mod) + text[i + m]) % mod;
        }
    }
    return ocorrencias;
}
