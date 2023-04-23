#include <iostream>
using namespace std;
int main()
{
    int a, b, r, q, aux;
    cin >> a >> b;
    if (a >= 0)
    {
        q = a / b;
        r = a % b;
    }
    else
    {
        int x = 0, y = 0;

        if (b < 0)
        {
            x = b * -1;
        }
        else
        {
            x = b;
        }
        for (r = 0; r < x; r++)
        {
            y = a - r;
            if (y % b == 0)
            {
                break;
            }
        }
        q = y / b;
    }
    cout << q << " " << r << endl;
}