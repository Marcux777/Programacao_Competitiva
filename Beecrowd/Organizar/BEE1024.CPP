// CODIGO CORRIGIDO
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int main()
{
  int cteste;
  // freopen("saida.txt", "w", stdout);
  cin >> cteste;
  cin.ignore();
  string frase, crip1, crip2;

  for (int i = 0; i < cteste; i++)
  {
    getline(cin, frase);
    int tamanho = frase.size();

    for (int j = 0; j < tamanho; j++)
    {
      int letra = frase[j];

      if ((isalpha(frase[j])))
      {
        crip1 += letra + 3;
      }
      else
      {
        crip1 += frase[j];
      }
    }
    reverse(crip1.begin(), crip1.end());
    tamanho = crip1.size();
    crip2 = crip1;
    for (int j = tamanho / 2; j < tamanho; j++)
    {
      crip2[j] = crip2[j] - 1;
    }
    cout << crip2 << endl;
    crip2.clear();
    crip1.clear();
  }

  return 0;
}