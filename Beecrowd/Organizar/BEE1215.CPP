#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

string toLower(const string &str)
{
    string result = str;
    for (char &c : result)
    {
        c = tolower(c);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    string frase;
    set<string> dicionario;
    while (getline(cin, frase))
    {
        string aux;
        for (int i = 0; i <= frase.size(); i++)
        {
            if (isalpha(frase[i]))
            {
                aux += frase[i];
            }
            else
            {
                aux = toLower(aux);
                aux.erase(0, aux.find_first_not_of(" \t")); // remove espaços em branco no início
                aux.erase(aux.find_last_not_of(" \t") + 1); // remove espaços em branco no final

                if (!aux.empty())
                {
                    dicionario.insert(aux);
                }
                aux = "";
            }
        }
    }
    for (auto it : dicionario)
    {
        cout << it << endl;
    }
}