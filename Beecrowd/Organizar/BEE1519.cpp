#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    string frase, aux;
    while (getline(cin, frase) && frase != ".")
    {
        frase += " ";
        vector<string> v;
        int cont = 0;
        map<string, int> colecao;
        for (int i = 0; i < frase.size(); i++)
        {
            if (isalpha(frase[i]))
            {
                aux += frase[i];
            }
            else
            {
                v.push_back(aux);
                if (aux.size() > 2)
                {
                    colecao[aux] += aux.size() - 2;
                }
                else
                {
                    colecao[aux] = aux.size();
                }
                aux.clear();
            }
        }
        map<string, string> mp;
        for (auto it : colecao)
        {
            if (it.first.size() > 2)
            {
                // vai guardar a abreviação
                string aux = it.first.substr(0, 1) + '.';
                if (!mp.count(aux))
                {
                    // não existe a abreviação
                    mp[aux] = it.first;
                    cont++;
                }
                else
                {
                    // existe a abreviação
                    // se existe, tenho que olhar quem será mais eficiente na minha abreviação
                    // por isso, tenho que buscar no meu map colecao para achar qual será mais eficiente
                    auto it1 = mp.find(aux);
                    auto it2 = colecao.find(it1->second);
                    if (it.second > it2->second)
                    {
                        mp[aux] = it.first;
                    }
                }
            }
        }
        for (auto it : mp)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == it.second)
                {
                    v[i] = it.first;
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i < v.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
        cout << cont << endl;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            cout << i->first << " = " << i->second << endl;
        }
    }
}