#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Estrutura para armazenar as coordenadas de uma nave
struct Nave
{
    int x, y, z;
};

// Função para calcular a distância entre duas naves
double calcularDistancia(Nave n1, Nave n2)
{
    double dx = n1.x - n2.x;
    double dy = n1.y - n2.y;
    double dz = n1.z - n2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int n;
    cin >> n;

    vector<Nave> naves(n);
    for (int i = 0; i < n; i++)
    {
        cin >> naves[i].x >> naves[i].y >> naves[i].z;
    }

    for (int i = 0; i < n; i++)
    {
        double menorDistancia = 1e9; // valor muito grande para iniciar a variável
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            { // não comparar uma nave com ela mesma
                double distancia = calcularDistancia(naves[i], naves[j]);
                if (distancia < menorDistancia)
                {
                    menorDistancia = distancia;
                }
            }
        }
        if (menorDistancia <= 20)
        {
            cout << "A\n";
        }
        else
        {
            if (menorDistancia <= 50)
            {
                cout << "M\n";
            }
            else
            {
                cout << "B\n";
            }
        }
    }

    return 0;
}
