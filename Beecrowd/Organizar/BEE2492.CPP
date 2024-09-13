#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    while (cin >> t && t)
    {
        map<string, string> rota;
        bool Func = true, InFunc = true;
        for (int i = 0; i < t; i++)
        {
            string a, b, setinha;
            cin >> a >> setinha >> b;
            if (rota.count(a) && rota[a] != b)
            {
                Func = false;
            }
            else
            {
                rota[a] = b;
            }
        }
        map<string, int> ocorrencias;
        for (auto it = rota.begin(); it != rota.end(); it++)
        {
            ocorrencias[it->second]++; // conta quantas vezes cada ilha é destino de uma conexão
        }
        for (auto it = ocorrencias.begin(); it != ocorrencias.end() && InFunc; it++)
        {
            if (it->second > 1)
            { // se alguma ilha é destino de mais de uma conexão, a função não é invertível
                InFunc = false;
            }
        }
        if (!Func)
        {
            cout << "Not a function." << endl;
        }
        else
        {
            if (InFunc)
            {
                cout << "Invertible." << endl;
            }
            else
            {
                cout << "Not invertible." << endl;
            }
        }
    }
}