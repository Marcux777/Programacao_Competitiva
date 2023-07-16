#include <iostream>

using namespace std;

int main()
{
    int t, caso = 0;
    while (cin >> t && t)
    {
        int cont = 0;
        for (int i = 0; i < t; i++)
        {
            int a;
            cin >> a;
            if (a != 0)
            {
                cont++;
            }
            else
            {
                cont--;
            }
        }
        cout << "Case " << ++caso << ": " << cont << endl;
    }
}