#include <iostream>
using namespace std;
int main()
{
    int x, maior = -1, posicao;
    for (int i = 1; i <= 100; i++)
    {
        cin >> x;
        if (x > maior)
        {
            maior = x;
            posicao = i;
        }
    }
    cout << maior << "\n"
         << posicao << "\n";
    return 0;
}