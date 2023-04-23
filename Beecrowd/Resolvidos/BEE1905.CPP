#include <iostream>
using namespace std;

int x[5][5];

void peganao(int i, int j)
{
	if (x[i][j] == 0)
	{
		x[i][j] = 2;
	}
	if (i > 0 && x[i - 1][j] == 0)
	{
		peganao(i - 1, j);
	}
	if (i < 4 && x[i + 1][j] == 0)
	{
		peganao(i + 1, j);
	}
	if (j > 0 && x[i][j - 1] == 0)
	{
		peganao(i, j - 1);
	}
	if (j < 4 && x[i][j + 1] == 0)
	{
		peganao(i, j + 1);
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> x[i][j];
			}
		}
		peganao(0, 0);
		if (x[4][4] == 2)
		{
			cout << "COPS" << endl;
		}
		else
		{
			cout << "ROBBERS" << endl;
		}
	}
}
