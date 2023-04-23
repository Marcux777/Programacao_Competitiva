#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    int v[16];
    for (int i = 0; i < 16; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < 16; i++)
    {
        if (v[i] == 1)
        {
            n1 = i;
        }
        if (v[i] == 9)
        {
            n2 = i;
        }
    }
    if (((n1) / 2) == ((n2) / 2))
    {
        cout << "oitavas" << endl;
    }
    else
    {
        if (((n1) / 4) == ((n2) / 4))
        {
            cout << "quartas" << endl;
        }
        else
        {
            if (((n1) / 8) == ((n2) / 8))
            {
                cout << "semifinal" << endl;
            }
            else
            {
                cout << "final" << endl;
            }
        }
    }
}