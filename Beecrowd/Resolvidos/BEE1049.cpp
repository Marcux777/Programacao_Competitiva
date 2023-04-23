#include <iostream>
#include <string>
using namespace std;

int main()
{
	string nome1, nome2, nome3;
	cin >> nome1;
	cin >> nome2;
	cin >> nome3;
	if (nome1 == "vertebrado")
	{
		if (nome2 == "ave")
		{
			if (nome3 == "carnivoro")
			{
				cout << "aguia" << endl;
			}
			else if (nome3 == "onivoro")
			{
				cout << "pomba" << endl;
			}
		}
		else if (nome2 == "mamifero")
		{
			if (nome3 == "onivoro")
			{
				cout << "homem" << endl;
			}
			else if (nome3 == "herbivoro")
			{
				cout << "vaca" << endl;
			}
		}
	}
	else if (nome1 == "invertebrado")
	{
		if (nome2 == "inseto")
		{
			if (nome3 == "hematofago")
			{
				cout << "pulga" << endl;
			}
			else if (nome3 == "herbivoro")
			{
				cout << "lagarta" << endl;
			}
		}
		else if (nome2 == "anelideo")
		{
			if (nome3 == "hematofago")
			{
				cout << "sanguessuga" << endl;
			}
			else if (nome3 == "onivoro")
			{
				cout << "minhoca" << endl;
			}
		}
	}
}