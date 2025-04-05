#include <iostream>

vector<int> build_lps(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> KMP(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = build_lps(pattern);
    vector<int> ocorrencias;
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++, j++;
        }
        if (j == m) {
            ocorrencias.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            j = (j ? lps[j - 1] : 0);
        }
    }
    return ocorrencias;
}
