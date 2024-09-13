#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    freopen("saida.txt", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while (cin >> a >> b && (a != 0 || b != 0)) {
        // Inicializa a matriz de contagem
        int count[10][10] = {};
        
        // Preenche a matriz de contagem
        for (int i = 0; i < 10; i++) {
            count[i][0] = 0;
            for (int j = 1; j < 10; j++) {
                count[i][j] = count[i][j - 1];
                if (i == (j % 10)) {
                    count[i][j]++;
                }
            }
        }
        
        // Combina as contagens de cada dígito para formar a contagem total
        int result[10] = {};
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int digit_count = count[i][9] - count[i][0];
                if (a > 0) {
                    digit_count -= count[i][(a % 10) - 1];
                }
                digit_count += count[i][(b % 10)];
                result[i] += digit_count;
            }
        }
        
        // Imprime a contagem total de cada dígito
        for (int i = 0; i < 10; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
