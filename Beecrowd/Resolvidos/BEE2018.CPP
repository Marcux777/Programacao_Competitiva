#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Pais
{
public:
    int ouro;
    int prata;
    int bronze;
    string nome;
    Pais()
    {
        ouro = 0;
        prata = 0;
        bronze = 0;
    }
};

bool comp(Pais a, Pais b)
{
    if (a.ouro != b.ouro)
    {
        return a.ouro > b.ouro;
    }
    if (a.prata != b.prata)
    {
        return a.prata > b.prata;
    }
    if (a.bronze != b.bronze)
    {
        return a.bronze > b.bronze;
    }
    return a.nome < b.nome;
}

int main()
{
    string fds;
    //freopen("saida.txt", "w", stdout);
    vector<Pais> v;
    map<string, Pais> mp;
    map<string, Pais>::iterator it;
    while (getline(cin, fds))
    {
        string p;
        getline(cin, p);
        mp[p].ouro++;
        mp[p].nome = p;

        getline(cin, p);
        mp[p].prata++;
        mp[p].nome = p;

        getline(cin, p);
        mp[p].bronze++;
        mp[p].nome = p;
    }
    for (it = mp.begin(); it != mp.end(); it++)
    {
        v.push_back(it->second);
    }
    sort(v.begin(), v.end(), comp);
    cout << "Quadro de Medalhas" << endl;
    for (auto j : v)
    {
        cout << j.nome << " " << j.ouro << " " << j.prata << " " << j.bronze << endl;
    }
    return 0;
}
