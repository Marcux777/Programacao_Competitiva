#include <iostream>
using namespace std;
int main()
{
    int n, x, y, aux = 0;
    bool erro = false;
    while (cin >> n)
    {
        if (n > aux && erro == false)
        {
            aux = n;
        }
        else
        {
            erro = true;
        }
    }
    cout << aux + 1 << endl;
}