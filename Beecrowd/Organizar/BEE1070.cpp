#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int i = 0; i < 12; i++)
    {
        if ((x + i) % 2 != 0)
        {
            cout << x + i << endl;
        }
    }
}