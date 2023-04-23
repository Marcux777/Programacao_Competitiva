#include <iostream>
using namespace std;
int main()
{
	int c1, c2, c3, c4, pos;
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == 1)
	{
		pos = 1;
	}
	else
	{
		if (c2 == 1)
		{
			pos = 2;
		}
		else
		{
			if (c3 == 1)
			{
				pos = 3;
			}
			else
			{
				if (c4 == 1)
				{
					pos = 4;
				}
			}
		}
	}
	cout << pos << endl;
}
