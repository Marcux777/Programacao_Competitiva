#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double M[12][12];
	int i, j, L;
	char T;
	float soma = 0.0;

	cin >> L;
	cin >> T;

	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 12; j++)
		{
			cin >> M[i][j];
			if (i == L)
			{
				soma += M[i][j];
			}
		}
	}
	if (T == 'S')
	{
		cout << fixed << setprecision(1) << soma << endl;
	}
	else if (T == 'M')
	{
		cout << fixed << setprecision(1) << soma / 12.0 << endl;
	}
}