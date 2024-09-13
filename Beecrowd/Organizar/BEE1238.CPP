#include <iostream>

using namespace std;

int main()
{
	int n;
	string s1, s2;
	string v;
	cin >> n;
	while (n--)
	{
		int i = 0;
		cin >> s1 >> s2;
		if (s1.size() > s2.size())
		{
			for (i = 0; i < s2.size(); i++)
			{
				v.push_back(s1[i]);
				v.push_back(s2[i]);
			}
			for (; i < s1.size(); i++)
			{
				v.push_back(s1[i]);
			}
		}
		else
		{
			for (i = 0; i < s1.size(); i++)
			{
				v.push_back(s1[i]);
				v.push_back(s2[i]);
			}
			for (; i < s2.size(); i++)
			{
				v.push_back(s2[i]);
			}
		}
		cout << v << endl;
		v.clear();
	}
}
