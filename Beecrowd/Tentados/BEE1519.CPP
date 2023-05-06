#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line) && line != ".") {
        stringstream ss(line);
        string word;
        map<char, string> abbreviations;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
            if (word.length() <= 2) continue; // palavras com 2 letras ou menos não podem ser abreviadas
            char c = word[0];
            if (abbreviations.count(c) == 0) { // ainda não há uma abreviação para essa letra
                abbreviations[c] = word;
            } else if (abbreviations[c].length() > word.length() + 2) { // abreviação atual é maior que nova abreviação proposta
                abbreviations[c] = word;
            }
        }

        // Aplicar as abreviações na frase
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            char c = word[0];
            if (abbreviations.count(c) && abbreviations[c] == word) {
                cout << c << ". ";
            } else {
                cout << word << " ";
            }
        }
        cout << endl;

        // Imprimir lista de abreviações
        cout << abbreviations.size() << endl;
        for (auto it = abbreviations.begin(); it != abbreviations.end(); ++it) {
            cout << it->first << ". = " << it->second << endl;
        }
    }

    return 0;
}
