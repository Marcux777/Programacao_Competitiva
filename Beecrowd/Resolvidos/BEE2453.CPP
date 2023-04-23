#include <iostream>
using namespace std;
int main()
{
    string p;
    bool aux;
    getline(cin, p);
    aux = false;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == ' ')
        {
            cout << ' ';
            aux = !aux;
            continue;
        }

        if ((i % 2 == 0) == aux)
        {
            cout << p[i];
        }
    }
    cout << endl;
}