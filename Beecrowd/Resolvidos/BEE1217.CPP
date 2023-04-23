#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int t, fruta, totalfruta = 0, dia = 0;
	float preco, precot = 0;
	cin >> t;
	while (t--)
	{
		dia++;
		fruta = 1;
		cin >> preco;
		precot += preco;
		cin.ignore();
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				fruta++;
			}
		}
		totalfruta += fruta;
		cout << "day " << dia << ": ";
		cout << fruta << " kg" << endl;
	}
	printf("%.2f kg by day\n", (float)totalfruta / dia);
	printf("R$ %.2f by day\n", (float)precot / dia);
}
