#include <iostream>
#include <string>

using namespace std;

int main() {
    int m;
    int resultado = 0;
    string expressao;
    int teste = 0;
    while (cin >> m && m != 0) {
        // lê a expressão
        cin >> expressao;
        // inicializa o resultado com o primeiro operando
        resultado = stoi(expressao.substr(0, expressao.find_first_of("+-")));
        // percorre a expressão
        for (int i = 0; i < expressao.size(); i++) {
            // se encontrar um operador +
            if (expressao[i] == '+') {
                // adiciona o próximo operando
                resultado += stoi(expressao.substr(i+1, expressao.find_first_of("+-", i+1) - i - 1));
            }
            // se encontrar um operador -
            if (expressao[i] == '-') {
                // subtrai o próximo operando
                resultado -= stoi(expressao.substr(i+1, expressao.find_first_of("+-", i+1) - i - 1));
            }
        }
        cout << "Teste " << ++teste << endl;
        cout << resultado << endl;
        cout << endl;
    }
    return 0;
}