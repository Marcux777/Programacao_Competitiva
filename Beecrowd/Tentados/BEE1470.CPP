#include <bits/stdc++.h>

using namespace std;

bool verifica(vector<int> a, vector<int> b)
{
    int k = 0, tam = a.size();
    vector<bool> v(tam);
    v.assign(v.size(), false);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++) // Corrigido: loop de j estava com a condição invertida
        {
            int sum = a[i] + a[j];
            auto it = find(b.begin(), b.end(), sum);
            if (it != b.end())
            {
                v[k] = true;
                k++;
            }
        }
    }
    for (int i = 0; i < tam; i++)
    {
        if (v[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    freopen("saida.txt", "w", stdout);
    while (cin >> n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cin >> m;
        vector<int> res(m);
        for (int i = 0; i < m; i++)
        {
            cin >> res[i];
        }
        if (verifica(v, res))
        {
            cout << "S\n";
        }
        else
        {
            cout << "N\n";
        }
    }
    return 0; // Adicionado: indicar que o programa finalizou sem erros
}
