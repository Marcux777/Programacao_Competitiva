#include <iostream>
using namespace std;
bool primo(int x)
{
    int i, div = 0;
    for (i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            div++;
        }
    }
    if (div > 2)
    {
        return false;
    }
    else
    {
        if (div == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    bool x;
    bool y;
    int n, s = 0, p1, p2;
    cin >> n;
    while (s < 2)
    {
        x = primo(n);
        if (x == true)
        {
            p1 = n;
            s += 1;
            y = primo(n - 2);
            if (y == true)
            {
                p2 = n - 2;
                s = s + 1;
            }
            else
            {
                s = 0;
                x = false;
            }
        }
        n = n - 1;
    }
    cout << p2 << ' ' << p1 << endl;
}