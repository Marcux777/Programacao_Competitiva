#include <iostream>

using namespace std;

int main()
{
	int n, soma = 0, x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x > y)
		{
			soma += y;
		}
	}
	cout << soma << endl;
}
