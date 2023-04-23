#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> capturados;
    string nome;
    for (int i = 0; i < n; i++)
    {
        cin >> nome;
        capturados.insert(nome);
    }

    int faltam = 151 - capturados.size();
    cout << "Falta(m) " << faltam << " pomekon(s)." << endl;

    return 0;
}
