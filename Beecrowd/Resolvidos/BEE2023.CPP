#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

bool comp(string a, string b)
{
    return a < b;
}

int main()
{
    string nome;
    map<string, string> lista;
    while (getline(cin, nome))
    {
        string a;
        for (char &c : nome)
        {
            a += tolower(c);
        }
        lista[a] = nome;
    }
    auto it = prev(lista.end());
    cout << it->second << endl;
}