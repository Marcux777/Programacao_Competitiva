#include <iostream>
using namespace std;

int main() {
    int n;
    //freopen("saida.txt", "w", stdout);
    cin >> n;
    cin.ignore(); // usado para ignorar o enter digitado após o número de casos de teste

    while (n--) {
        string texto, final;
        getline(cin, texto);

        for (int i = 0; i < texto.size(); i++) {
            if (texto[i] != ' ') {
                if(i == 0){
                    final += texto[i];
                }else{
                    if(texto[i-1] == ' '){
                        final += texto[i];
                    }
                }
            }
        }
        cout << final << endl;
    }

    return 0;
}
