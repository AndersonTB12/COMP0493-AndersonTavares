/*
    Implementação dos métodos de entrada de dados sugeridos nas seções 1.4.2 e 1.5 do livro do Halim.
*/

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
    // Método 1: Leitura com scanf e printf
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);

    // Método 2: Leitura com cin e cout
    string s;
    cin >> s;
    cout << "String lida: " << s << endl;

    // Método 3: Leitura de linha inteira com getline
    cin.ignore();  // Ignorar a quebra de linha pendente
    string line;
    getline(cin, line);
    cout << "Linha lida: " << line << endl;

    // Método 4: Leitura de múltiplos valores com istringstream
    istringstream iss(line);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    cout << "Palavras extraídas da linha: ";
    for (const auto &w : words) {
        cout << w << " ";
    }
    cout << endl;

    // Método 5: Leitura de arquivos com freopen
    freopen("input.txt", "r", stdin);
    int x;
    while (cin >> x) {
        cout << "Lido do arquivo: " << x << endl;
    }
    fclose(stdin);
    
    return 0;
}
