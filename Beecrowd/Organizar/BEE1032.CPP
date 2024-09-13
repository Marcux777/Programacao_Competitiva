#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        // freopen("saida.txt", "w", stdout);
        //  Criar vetor de pessoas
        vector<int> pessoas(n);
        for (int i = 0; i < n; i++)
        {
            pessoas[i] = i + 1;
        }

        // Inicializar variáveis
        int m = 1;
        int idx = 0;

        while (pessoas.size() > 1)
        {
            // Encontrar próximo primo
            m++;
            while (!is_prime(m))
            {
                m++;
            }

            // Eliminar pessoa
            idx = (idx + m - 1) % pessoas.size();
            pessoas.erase(pessoas.begin() + idx);
        }

        // Imprimir sobrevivente
        cout << pessoas[0] << endl;
    }
    return 0;
}