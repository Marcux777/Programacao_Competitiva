#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		int d;
		cin >> s;
		cin >> d;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] < 'A' + d)
			{
				s[i] = 'Z' - d + (s[i] - 'A') + 1;
			}
			else
			{
				s[i] -= d;
			}
		}
		cout << s << endl;
		s.clear();
	}
}
