#include <iostream>
using namespace std;
int main()
{
	char frase;
	int cont = 0;
	while (scanf("%c", &frase) != EOF)
	{
		if (frase == 'j' || frase == 'p' || frase == 's' || frase == 'v' || frase == 'b' || frase == 'x' || frase == 'z')
		{
			frase = 'f';
			if (cont == 0)
			{
				cout << frase;
				cont++;
			}
		}
		else if (frase == 'J' || frase == 'P' || frase == 'S' || frase == 'V' || frase == 'B' || frase == 'X' || frase == 'Z')
		{
			frase = 'F';
			if (cont == 0)
			{
				cout << frase;
				cont++;
			}
		}
		else
		{
			if (frase == 'F' || frase == 'f')
			{
				if (cont == 0)
				{
					cout << frase;
					cont++;
				}
			}
			else
			{
				cout << frase;
				cont = 0;
			}
		}
	}
}
