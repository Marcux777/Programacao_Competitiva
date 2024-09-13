#include <iostream>
using namespace std;
int main()
{
    int c, s, n;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        s = 0;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
}