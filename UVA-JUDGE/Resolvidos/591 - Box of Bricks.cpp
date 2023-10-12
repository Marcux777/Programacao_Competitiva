#include <iostream>
#include <algorithm>
#include <numeric> // para a funcao accumulate

using namespace std;

int main()
{
    int n, heights[50];
    int set_num = 0; // contador de conjuntos de entrada
    while (cin >> n && n != 0)
    {                       // le o numero de tijolos de cada pilha ate n = 0
        set_num++;          // incrementa o contador de conjunto de entrada
        int avg, moves = 0; // inicializa a media e o contador de movimentos
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];   // le as alturas das pilhas
            moves += heights[i]; // soma a altura da pilha atual no contador de movimentos
        }
        avg = moves / n; // calcula a altura media das pilhas
        moves = 0;       // reinicia o contador de movimentos
        for (int i = 0; i < n; i++)
        {
            moves += abs(heights[i] - avg); // acumula a diferenca entre a altura atual e a media
        }
        moves /= 2; // divide o contador de movimentos por 2, ja que dois tijolos sao movidos a cada operacao
        // Imprime o resultado
        cout << "Set #" << set_num << endl;
        cout << "The minimum number of moves is " << moves << "." << endl
             << endl;
    }
    return 0;
}
