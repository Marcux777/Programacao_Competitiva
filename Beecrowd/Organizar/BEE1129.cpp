#include <iostream>
using namespace std;
int main()
{
    int n, nota[5], cont;                             // nota é na vdd a letra marcada :P
    char notaf, letra[7] = {'A', 'B', 'C', 'D', 'E'}; // notaf vai ser a marcação final
    cin >> n;
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cont = 0;
            for (int j = 0; j < 5; j++)
            {
                cin >> nota[j];
            }
            for (int j = 0; j < 5; j++)
            {
                if (nota[j] <= 127)
                {
                    cont++;
                    notaf = letra[j];
                }
            }
            if (cont >= 2 || cont == 0)
            {
                notaf = '*';
            }
            cout << notaf << endl;
        }
        cin >> n;
    }
}