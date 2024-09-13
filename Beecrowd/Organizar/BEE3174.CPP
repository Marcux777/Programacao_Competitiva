#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nome, trab;
    int carga, n;
    int bcarga = 0, acarga = 0, mcarga = 0, dcarga = 0, nbrinq = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nome >> trab >> carga;
        if (trab == "bonecos")
        {
            bcarga += carga;
        }
        else if (trab == "arquitetos")
        {
            acarga += carga;
        }
        else if (trab == "musicos")
        {
            mcarga += carga;
        }
        else if (trab == "desenhistas")
        {
            dcarga += carga;
        }
    }
    nbrinq = (bcarga / 8) + (acarga / 4) + (mcarga / 6) + (dcarga / 12);
    cout << nbrinq << endl;
}
