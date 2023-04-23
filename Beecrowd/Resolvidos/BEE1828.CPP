#include <iostream>
#include <string>

using namespace std;
int main()
{
    int t;
    string sheldon, rj;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> sheldon;
        cin >> rj;
        if (sheldon == rj)
        {
            cout << "Caso #" << i + 1 << ": De novo!" << endl;
        }
        else if (sheldon == "tesoura" && rj == "papel")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "tesoura" && rj == "lagarto")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "papel" && rj == "pedra")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "papel" && rj == "Spock")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "pedra" && rj == "lagarto")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "pedra" && rj == "tesoura")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "lagarto" && rj == "Spock")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "lagarto" && rj == "papel")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "Spock" && rj == "tesoura")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else if (sheldon == "Spock" && rj == "pedra")
        {
            cout << "Caso #" << i + 1 << ": Bazinga!" << endl;
        }
        else
        {
            cout << "Caso #" << i + 1 << ": Raj trapaceou!" << endl;
        }
    }
}