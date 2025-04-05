#include <iostream>

vector<int> preprocess_boyer_moore(const string& pattern) {
    const int ALPHABET = 256;
    vector<int> last(ALPHABET, -1);
    for (int i = 0; i < pattern.size(); ++i)
        last[(unsigned char)pattern[i]] = i;
    return last;
}

vector<int> BoyerMoore(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> last = preprocess_boyer_moore(pattern);
    vector<int> ocorrencias;

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) j--;
        if (j < 0) {
            ocorrencias.push_back(s);
            s += (s + m < n) ? m - last[(unsigned char)text[s + m]] : 1;
        } else {
            s += max(1, j - last[(unsigned char)text[s + j]]);
        }
    }
    return ocorrencias;
}
