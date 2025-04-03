#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A;
    string B;
    cin >> A >> B;

    // Remove o ponto decimal e converte para inteiro
    int B_int = (B[0] - '0') * 100 + (B[2] - '0') * 10 + (B[3] - '0');

    // Calcula o produto e divide por 100 (truncando)
    long long result = (A * B_int) / 100;

    cout << result << endl;
    return 0;
}
