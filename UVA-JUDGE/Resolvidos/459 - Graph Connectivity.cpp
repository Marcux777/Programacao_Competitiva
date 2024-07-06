#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[27];
vector<int> vet[27];
string s;
int cont;

void inicia()
{
	cont = 0;
	for (int i = 0; i < 26; i++)
	{
		vis[i] = false;
		vet[i].clear();
	}
}
void dfs(int u)
{
	vis[u] = true;

	for (auto i : vet[u])
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		inicia();
		char let;
		cin >> let;
		cin.ignore();
		n = let - 'A' + 1;
		while (getline(cin, s) && s!= "")
		{
			int x, y;
			x = s[0] - 'A';
			y = s[1] - 'A';
			vet[x].push_back(y);
			vet[y].push_back(x);
		}
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				cont++;
				dfs(i);
			}
		}
		cout << cont << endl;
		if(t) cout << endl;
	}
}
