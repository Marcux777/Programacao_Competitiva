#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t, a, w, c, perc;
	string s;
	cin >> t >> a >> w >> c;
	perc = (100 * a) / t;
	if (perc < w)
	{
		s = "OK";
	}
	else
	{
		if (perc >= w && perc < c)
		{
			s = "warning";
		}
		else
		{
			if (perc >= c)
			{
				s = "critical";
			}
		}
	}
	cout << s << endl;
}
