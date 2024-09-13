#include <iostream>
using namespace std;
int main()
{
    int n, cont = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i < 10)
        {
            cont++;
        }
        else
        {
            if (i < 100)
            {
                cont += 2;
            }
            else
            {
                if (i < 1000)
                {
                    cont += 3;
                }
                else
                {
                    if (i < 10000)
                    {
                        cont += 4;
                    }
                    else
                    {
                        if (i < 100000)
                        {
                            cont += 5;
                        }
                        else
                        {
                            cont += 6;
                        }
                    }
                }
            }
        }
    }
    cout << cont << endl;
}