#include <iostream>
using namespace std;
int main()
{
    int Fd, Bd, Md, Fp, Bp, Mp, soma = 0;
    cin >> Fd >> Bd >> Md;
    cin >> Fp >> Bp >> Mp;
    if (Fd < Fp)
    {
        soma = soma + (Fp - Fd);
    }
    if (Bd < Bp)
    {
        soma = soma + (Bp - Bd);
    }
    if (Md < Mp)
    {
        soma = soma + (Mp - Md);
    }
    cout << soma << endl;
}