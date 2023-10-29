#include <bits/stdc++.h>

using namespace std;

// Declaração de variáveis globais
vector<vector<string>> row(3);
bool found = false;
int n;
string r, c;
vector<string> grid;

// Função de busca em profundidade
void dfs(int index, int flag)
{
    // Se já encontramos uma solução, retornamos
    if (found)
    {
        return;
    }

    // Se chegamos ao final da string, verificamos se encontramos uma solução
    if (index == n)
    {
        if (flag == 0)
        {
            cout << "Yes\n";
            for (auto &next : grid)
            {
                cout << next << "\n";
            }
            found = true;
        }
        return;
    }

    // Para cada permutação possível, tentamos adicionar à grade e chamar a função dfs para o próximo índice
    for (auto &next : row[r[index] - 'A'])
    {
        grid.push_back(next);

        int updatedFlag = flag;
        bool undo = true;
        for (int j = 0; j < n; j++)
        {
            if (next[j] == '.')
            {
                continue;
            }
            int kind = (next[j] - 'A');

            // Verifica se o caractere atual já apareceu na mesma posição em uma string anterior usando operador binário AND (&)
            if ((flag & (1 << (4 * j + kind))) == 0)
            {
                undo = false;
                break;
            }

            // Atualiza a máscara de bits `updatedFlag`, removendo o bit correspondente ao caractere atual usando operador binário XOR (^)
            updatedFlag ^= (1 << (4 * j + kind));

            // Verifica se o caractere atual é igual ao caractere correspondente na string `c` usando operador binário AND (&)
            if ((flag & (1 << (4 * j + 3))) != 0)
            {
                if (next[j] != c[j])
                {
                    undo = false;
                    break;
                }

                // Atualiza a máscara de bits `updatedFlag`, removendo o bit correspondente ao caractere atual usando operador binário XOR (^)
                updatedFlag ^= (1 << (4 * j + 3));
            }
        }

        // Se a string atual satisfaz as condições, chamamos a função dfs para o próximo índice
        if (undo)
        {
            dfs(index + 1, updatedFlag);
        }

        // Removemos a string atual da grade
        grid.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Leitura da entrada do usuário
    cin >> n >> r >> c;

    // Geração de todas as permutações possíveis de uma string contendo A, B e C
    string abc = "ABC";
    while (abc.size() < n)
    {
        abc.push_back('.');
    }
    sort(abc.begin(), abc.end());

    do
    {
        char target = '.';
        for (auto &next : abc)
        {
            if (next != '.')
            {
                target = next;
                break;
            }
        }
        row[target - 'A'].push_back(abc);
    } while (next_permutation(abc.begin(), abc.end()));

    // Chamada da função dfs com o índice inicial e a máscara de bits inicial
    dfs(0, (1 << (4 * n)) - 1); // O operador '<<' é um operador de deslocamento à esquerda. Ele desloca os bits do número à esquerda pelo número de posições especificado.

    // Se não encontramos uma solução, imprimimos "No"
    if (!found)
    {
        cout << "No\n";
    }

    return 0;
}
