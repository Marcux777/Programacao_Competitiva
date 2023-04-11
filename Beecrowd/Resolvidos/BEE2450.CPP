#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matriz(n, vector<int>(m));

    // leitura da matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matriz[i][j];
        }
    }

    bool esta_escada = true;

    for (int i = 0; i < n && esta_escada; i++)
    {
        bool linha_sozinhos_zeros = true;
        int indice_primeiro_diferente_zero = -1;

        for (int j = 0; j < m; j++)
        {
            if (matriz[i][j] != 0)
            {
                linha_sozinhos_zeros = false;
                if (indice_primeiro_diferente_zero == -1)
                {
                    indice_primeiro_diferente_zero = j;
                }
            }
        }

        if (linha_sozinhos_zeros)
        {
            for (int k = i + 1; k < n; k++)
            {
                for (int j = 0; j < m && esta_escada; j++)
                {
                    if (matriz[k][j] != 0)
                    {
                        esta_escada = false;
                    }
                }
            }
        }
        else
        {
            for (int k = i + 1; k < n && esta_escada; k++)
            {
                bool elementos_esquerda_x_iguais_zero = true;
                for (int j = 0; j < indice_primeiro_diferente_zero && elementos_esquerda_x_iguais_zero; j++)
                {
                    if (matriz[k][j] != 0)
                    {
                        elementos_esquerda_x_iguais_zero = false;
                    }
                }

                if (!elementos_esquerda_x_iguais_zero || matriz[k][indice_primeiro_diferente_zero] != 0)
                {
                    esta_escada = false;
                }
            }
        }
    }

    if (esta_escada)
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}
