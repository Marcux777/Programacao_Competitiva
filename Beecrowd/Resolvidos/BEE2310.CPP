#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, nS[100], nB[100], nA[100];
    int S[100], B[100], A[100];
    int Ss = 0, Sb = 0, Sa = 0, Sums = 0, Sumb = 0, Suma = 0;
    char nome[20];
    cin >> n;
    cout << setprecision(2) << fixed;
    for (int i = 0; i < n; i++)
    {
        cin >> nome;
        cin >> nS[i] >> nB[i] >> nA[i];
        cin >> S[i] >> B[i] >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        Ss += nS[i];
        Sb += nB[i];
        Sa += nA[i];
        Sums += S[i];
        Sumb += B[i];
        Suma += A[i];
    }
    cout << "Pontos de Saque: " << 100.00 * Sums / Ss << " %." << endl;
    cout << "Pontos de Bloqueio: " << 100.00 * Sumb / Sb << " %." << endl;
    cout << "Pontos de Ataque: " << 100.00 * Suma / Sa << " %." << endl;
}