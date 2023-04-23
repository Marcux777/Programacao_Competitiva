#include <iostream>
#include <stack>
using namespace std;
int main()
{
	char e[100], s[100]; // entrada e saida
	int n;
	cin >> n;
	while (n != 0)
	{
		stack<char> est;
		for (int i = 0; i < n; i++)
		{
			cin >> e[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		int i = 0;
		int j = 0;
		while (i < n)
		{
			if (est.size() > 0 && s[i] == est.top())
			{
				est.pop();
				cout << 'R';
				i++;
			}
			else
			{
				if (j < n)
				{
					est.push(e[j]);
					j++;
					cout << 'I';
				}
				else
				{
					i = n;
				}
			}
		}

		if (est.size() > 0)
		{
			cout << " Impossible" << endl;
		}
		else
		{
			cout << endl;
		}
		cin >> n;
	}
}
