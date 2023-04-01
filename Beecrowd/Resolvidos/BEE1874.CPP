#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, p, f;
    
    while (cin >> h >> p >> f && h != 0 && p != 0 && f != 0) {
        // Criar a matriz de estoque
        vector<vector<int>> estoque(h, vector<int>(p, 0));
        
        // Ler os valores do estoque
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < p; j++) {
                cin >> estoque[i][j];
            }
        }
        
        // Ler os valores da fila de blocos novos
        vector<int> novos_blocos(f);
        for (int i = 0; i < f; i++) {
            cin >> novos_blocos[i];
        }
        
        // Inserir os blocos novos no estoque
        int fila_idx = 0;
        bool inseriu = true;
        while (inseriu && fila_idx < f) {
            inseriu = false;
            for (int j = p-1; j >= 0; j--) {
                for (int i = h-1; i >= 0; i--) {
                    if (estoque[i][j] == 0) {
                        estoque[i][j] = novos_blocos[fila_idx];
                        fila_idx++;
                        inseriu = true;
                        i = -1;
                    }
                }
                if (inseriu) j = -1;
            }
        }
        
        // Imprimir o estoque atualizado
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < p; j++) {
                cout << estoque[i][j];
                if (j < p-1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
