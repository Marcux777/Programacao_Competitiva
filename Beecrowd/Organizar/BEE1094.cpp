#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, quant, coelho = 0, rato = 0, sapo = 0, soma = 0, total = 0;
    double percc, percr, percs;
    char animal;
    cout << setprecision(2) << fixed;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> quant >> animal;
        total += quant;
        if (animal == 'C')
        {
            coelho += quant;
        }
        else if (animal == 'R')
        {
            rato += quant;
        }
        else
        {
            sapo += quant;
        }
    }
    percc = float(coelho) * 100 / total;
    percr = float(rato) * 100 / total;
    percs = float(sapo) * 100 / total;
    cout << "Total: " << total << " cobaias" << endl;
    cout << "Total de coelhos: " << coelho << endl;
    cout << "Total de ratos: " << rato << endl;
    cout << "Total de sapos: " << sapo << endl;
    cout << "Percentual de coelhos: " << percc << " %" << endl;
    cout << "Percentual de ratos: " << percr << " %" << endl;
    cout << "Percentual de sapos: " << percs << " %" << endl;
}