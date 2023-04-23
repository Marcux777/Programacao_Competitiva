#include <iostream>
using namespace std;
int main()
{
    int gasosa = 0, diesel = 0, alcool = 0;
    int resp;
    cin >> resp;
    while (resp != 4)
    {
        if (resp == 1)
        {
            alcool++;
        }
        else if (resp == 2)
        {
            gasosa++;
        }
        else if (resp == 3)
        {
            diesel++;
        }
        cin >> resp;
    }
    cout << "MUITO OBRIGADO" << endl;
    cout << "Alcool: " << alcool << endl;
    cout << "Gasolina: " << gasosa << endl;
    cout << "Diesel: " << diesel << endl;
}