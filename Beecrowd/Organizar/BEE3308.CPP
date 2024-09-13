#include <iostream>
using namespace std;
int main()
{
    int n, m, a1, a2, a3, cont;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m >> a1 >> a2 >> a3;
        cont = a1 + a2 + a3;
        if (cont > 1)
        {
            cout << 'X' << endl;
        }
        else
        {
            if (m == 0)
            {
                if (cont == 0)
                {
                    cout << '0' << endl;
                }
                else
                {
                    cout << '1' << endl;
                }
            }
            else
            {
                cout << '0' << endl;
            }
        }
    }
}