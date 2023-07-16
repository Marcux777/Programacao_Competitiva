#include <iostream>
#include <vector>

using namespace std;

void imprime(int v1, int v2)
{
    int cont = 0;
    int backup1 = v1;
    int backup2 = v2;
    while (v1)
    {
        cont++;
        v1 /= 10;
    }
    if (cont == 1)
    {
        cout << "  " << backup1;
    }
    else
    {
        if (cont == 2)
        {
            cout << " " << backup1;
        }
        else
        {
            cout << backup1;
        }
    }
    cont = 0;
    while (v2)
    {
        cont++;
        v2 /= 10;
    }
    if (cont == 1)
    {
        cout << "  " << backup2;
    }
    else
    {
        if (cont == 2)
        {
            cout << " " << backup2;
        }
        else
        {
            cout << backup2;
        }
    }
}

void imprime(int v1)
{
    int cont = 0;
    int backup = v1;
    while (v1)
    {
        cont++;
        v1 /= 10;
    }
    if (cont == 1)
    {
        cout << "  " << backup;
    }
    else
    {
        if (cont == 2)
        {
            cout << " " << backup;
        }
        else
        {
            cout << backup;
        }
    }
}

int main()
{
    int N, k, m;
    while (cin >> N >> k >> m && (N + k + m))
    {
        vector<int> v, final;
        for (int i = 0; i < N; i++)
        {
            v.push_back(i + 1);
        }
        int valor1, valor2;
        while (!v.empty())
        {
            for (int i = 0; i < k; i++)
            {
                v.push_back(v[0]);
                v.erase(v.begin());
            }
            valor1 = v[0];
            v.erase(v.begin());
            int tam = v.size() - 1;
            valor2 = v[tam - m];
            v.erase(v.begin() + (tam - m));
            if (valor1 != valor2)
            {
                imprime(valor1, valor2);
                if (v.size() > 1)
                {
                    cout << ",";
                }
            }
            else
            {
                imprime(valor1);
            }
        }
    }
}