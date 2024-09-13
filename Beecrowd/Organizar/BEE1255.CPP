#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // para ignorar a quebra de linha depois do número de casos de teste
    while (n--)
    {
        string s;
        getline(cin, s);    // para ler a linha inteira, incluindo espaços
        int freq[26] = {0}; // inicializar todas as frequencias como 0
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {                                // verificar se o caractere é uma letra
                freq[tolower(s[i]) - 'a']++; // incrementar a frequencia da letra
            }
        }
        int max_freq = 0;
        for (int i = 0; i < 26; i++)
        {
            max_freq = max(max_freq, freq[i]); // encontrar a maior frequencia
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == max_freq)
            { // imprimir as letras de maior frequencia
                cout << (char)(i + 'a');
            }
        }
        cout << endl;
    }
    return 0;
}
