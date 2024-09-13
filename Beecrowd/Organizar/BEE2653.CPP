#include <iostream>

using namespace std;

int main()
{
	// freopen("teste.txt", "w",stdin);
	// freopen("a.txt","w",stdout);
	string vet[1000], a;
	int cont = 0, stop = 0;
	while (cin >> a)
	{
		if (cont == 0)
		{
			vet[cont] = a;
			cont++;
		}
		else
		{
			for (int i = cont - 1; i >= 0 && stop == 0; i--)
			{
				if (vet[i] == a)
				{
					stop = 1;
				}
			}
			if (stop == 0)
			{
				vet[cont] = a;
				cont++;
			}
			stop = 0;
		}
	}
	cout << cont << endl;
}