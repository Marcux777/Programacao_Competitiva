#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int cont = 0;
	string s;
	cin >> s;
	for (int i = 0; s[i]; i++)
	{
		cont++;
	}
	if (cont >= 10)
	{
		cout << "palavrao" << endl;
	}
	else
	{
		cout << "palavrinha" << endl;
	}
}
