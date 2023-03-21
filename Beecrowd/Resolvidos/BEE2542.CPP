#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, L, CM, CL, A;
    //freopen("saida.txt", "w", stdout);
    while (cin >> N >> M >> L) {
        // Ler o baralho de Marcos
        vector<vector<int>> marcos(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> marcos[i][j];
            }
        }
        
        // Ler o baralho de Leonardo
        vector<vector<int>> leonardo(L, vector<int>(N));
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < N; j++) {
                cin >> leonardo[i][j];
            }
        }
        
        // Ler as cartas escolhidas e o atributo sorteado
        cin >> CM >> CL >> A;
        CM--; // O índice começa em 0
        CL--; // O índice começa em 0
        
        // Comparar os valores do atributo sorteado
        int valor_marcos = marcos[CM][A-1];
        int valor_leonardo = leonardo[CL][A-1];
        
        // Imprimir o resultado
        if (valor_marcos > valor_leonardo) {
            cout << "Marcos\n";
        } else if (valor_leonardo > valor_marcos) {
            cout << "Leonardo\n";
        } else {
            cout << "Empate\n";
        }
    }
    
    return 0;
}
