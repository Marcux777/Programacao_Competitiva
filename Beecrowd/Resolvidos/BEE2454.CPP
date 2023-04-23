#include <iostream>
using namespace std;
int main()
{
	char s;
	int a, b;
	cin >> a >> b;
	if (a == 1)
	{
		if (b == 1)
		{
			s = 'A';
		}
		else if (b == 0)
		{
			s = 'B';
		}
	}
	else
	{
		s = 'C';
	}
	cout << s << endl;
}
