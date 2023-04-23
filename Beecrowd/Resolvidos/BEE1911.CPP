#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    int n, m;
    while (cin >> n && n)
    {
        // freopen("saida.txt", "w", stdout);
        map<string, string> alunos;
        map<string, string> presentes;
        string nome, assinatura;

        while (n--)
        {
            cin >> nome >> assinatura;
            // cin.ignore();
            alunos[nome] = assinatura;
        }
        cin >> m;
        while (m--)
        {
            cin >> nome >> assinatura;
            // cin.ignore();
            presentes[nome] = assinatura;
        }
        int cont = 0, erros = 0;
        for (auto i : presentes)
        {
            auto it = alunos.find(i.first);
            for (int j = 0; j < int(i.second.size()); j++)
            {
                if (it->second[j] != i.second[j])
                {
                    erros++;
                }
            }
            if (erros > 1)
            {
                cont++;
            }
            erros = 0;
        }
        cout << cont << endl;
    }
}