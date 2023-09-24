#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int saida = -1;

    int Div = C / A;

    for (int i = 1; i * i <= Div; i++) {
        if (Div % i == 0) {
            int n1 = i * A; 
            int n2 = (Div / i) * A;

            if (n1 % B != 0 && C % n1 == 0 && D % n1 != 0) {
                if (saida == -1 || n1 < saida) {
                    saida = n1;
                }
            }

            if (n2 != n1 && n2 % B != 0 && C % n2 == 0 && D % n2 != 0) {
                if (saida == -1 || n2 < saida) {
                    saida = n2;
                }
            }
        }
    }

    cout << saida << endl; 
    return 0;
}
