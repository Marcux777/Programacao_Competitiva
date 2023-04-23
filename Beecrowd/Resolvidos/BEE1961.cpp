#include <iostream>
using namespace std;
int main()
{
    int p, n, dif, a, alt[100];
    cin >> p >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> alt[i];
    }
    a = 1;
    for (int i = 1; i < n; i++)
    {
        if (alt[i - 1] < alt[i])
        {
            dif = alt[i] - alt[i - 1];
            if (dif > p)
            {
                a = 0;
            }
        }
        else
        {
            dif = alt[i - 1] - alt[i];
            if (dif > p)
            {
                a = 0;
            }
        }
    }
    if (a == 1)
    {
        cout << "YOU WIN" << endl;
    }
    else
    {
        cout << "GAME OVER" << endl;
    }
}