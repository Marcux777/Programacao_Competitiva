#include <iostream>

using namespace std;
int main()
{
    int n, p = 0, b = 0;
    cin >> n;
    int m[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                b++;
            }
            else
            {
                if (i % 2 == 1 && j % 2 == 1)
                {
                    b++;
                }
                else
                {
                    p++;
                }
            }
        }
    }
    cout << b << " casas brancas e " << p << " casas pretas" << endl;
}