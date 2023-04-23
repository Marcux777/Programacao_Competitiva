#include <iostream>
using namespace std;
double crescimento(int x, int y, double a, double b)
{
	int c = 0;
	int aux;
	while (x <= y)
	{
		aux = x;
		x *= (a / 100);
		x += aux;
		if (b > 0.0)
		{
			aux = y;
			y *= (b / 100);
			y += aux;
		}
		c++;
	}
	return c;
}

int main()
{
	int t, A, B, v;
	float Pa, Pb;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> A >> B >> Pa >> Pb;
		v = crescimento(A, B, Pa, Pb);
		if (v > 100)
		{
			cout << "Mais de 1 seculo." << endl;
		}
		else
		{
			cout << v << " anos." << endl;
		}
	}
}
