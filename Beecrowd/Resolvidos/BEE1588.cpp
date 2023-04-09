#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("saida.txt", "w", stdout);
    int n;
    cin >> n;

     for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<vector<unsigned long long int>> matriz(m, vector<unsigned long long int>(m));

        // ler valores da matriz e encontrar o maior valor de cada coluna
        vector<unsigned long long int> max_values(m, 0);
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                cin >> matriz[j][k];
                if(matriz[j][k] > max_values[k]) {
                    max_values[k] = matriz[j][k];
                }
            }
        }

        // imprimir o quadrado da matriz com setw ajustado para o maior valor de cada coluna
        cout << "Quadrado da matriz #" << i+4 << ":" << endl;
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                int tamanho = to_string(max_values[k]*max_values[k]).length(); // tamanho do setw baseado no maior valor da coluna
                cout << setw(tamanho) << matriz[j][k]*matriz[j][k]; // imprimir valor quadrado com setw ajustado
                if(k < m-1){ //Imprimir espaço apenas se não for o ultimo número da linha
                    cout << " ";
                }
            }
            cout << endl;
        }

        if(i < n-1) { // imprimir linha em branco entre matrizes
            cout << endl;
        }
    }

    return 0;
}