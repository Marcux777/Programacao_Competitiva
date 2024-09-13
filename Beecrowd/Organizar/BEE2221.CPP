#include <iostream>
using namespace std;
int batalha_poke(int a, int b, int c, int d, int e, int f, int g)
{
	int dano1, dano2;
	dano1 = (a + b) / 2;
	dano2 = (d + e) / 2;
	if (c % 2 == 0)
	{
		dano1 += g;
	}
	if (f % 2 == 0)
	{
		dano2 += g;
	}
	if (dano1 > dano2)
	{
		return 1;
	}
	else if (dano1 < dano2)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
int main()
{
	int t, b, p;
	int atk1, atk2, def1, def2, lt1, lt2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> b;
		cin >> atk1 >> def1 >> lt1;
		cin >> atk2 >> def2 >> lt2;
		p = batalha_poke(atk1, def1, lt1, atk2, def2, lt2, b);
		if (p == 1)
		{
			cout << "Dabriel" << endl;
		}
		else if (p == 2)
		{
			cout << "Guarte" << endl;
		}
		else
		{
			cout << "Empate" << endl;
		}
	}
}
