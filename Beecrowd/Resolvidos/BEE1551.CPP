#include <bits/stdc++.h>
using namespace std;

string s;
int a[26]; // a[i] guarda a quantidade de vezes que a letra 'a'+i aparece na frase

int main()
{
	int n;
	//freopen("saida.txt", "w", stdout);
	cin >> n;
	getline(cin, s); // para consumir o '\n' restante
	while (n--)
	{
		getline(cin, s);		 // lê a frase inteira
		memset(a, 0, sizeof(a)); // zera o vetor a
		for (int i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]))			  // verifica se é uma letra
				a[tolower(s[i]) - 'a']++; // incrementa a quantidade de vezes que a letra apareceu na frase
		}
		int cont = 0;
		for (int i = 0; i < 26; i++)
		{
			if (a[i] > 0) // verifica se a letra apareceu na frase
				cont++;	  // incrementa o contador de letras diferentes
		}
		if (cont == 26)
			cout << "frase completa" << endl;
		else if (cont >= 13)
			cout << "frase quase completa" << endl;
		else
			cout << "frase mal elaborada" << endl;
	}
	return 0;
}