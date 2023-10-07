#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	string s;
	cin >> s;
	string palavra = "hello";
	queue<char> v;
	queue<char> esperado;
	for (auto i : palavra)
	{
		esperado.push(i);
	}
	for (auto i : s)
	{
		v.push(i);
	}
	while (!esperado.empty() && !v.empty())
	{
		char u = esperado.front();
		if (u == v.front())
		{
			esperado.pop();
		}
		v.pop();
	}
	if(esperado.empty()){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}