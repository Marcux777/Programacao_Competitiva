#include <iostream>
using namespace std;
void preenche_vetor(int x, int i = 0, int limite = 999)
{
    cout << "N[" << i << "] = " << i % x << endl;
    if (limite > i)
    {
        preenche_vetor(x, ++i, limite);
    }
}
int main()
{
    int n;
    cin >> n;
    preenche_vetor(n);
}