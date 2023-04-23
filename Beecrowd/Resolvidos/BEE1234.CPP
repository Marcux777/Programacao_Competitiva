#include <bits/stdc++.h>
using namespace std;

bool isletter(char aux)
{
	if ((aux >= 'a' && aux <= 'z') || (aux >= 'A' && aux <= 'Z'))
	{
		return true;
	}
	return false;
}

int main()
{
	string s;
	bool flag;

	while (getline(cin, s))
	{
		flag = true;
		for (int i = 0; i < s.size(); i++)
		{
			if (isletter(s[i]))
			{
				if (s[i] != ' ' && flag)
				{
					char aux;
					aux = s[i];
					aux = toupper(aux);
					s[i] = aux;
					flag = false;
				}
				else
				{
					char aux;
					aux = s[i];
					aux = tolower(aux);
					s[i] = aux;
					flag = true;
				}
			}
		}
		cout << s << endl;
	}
}
