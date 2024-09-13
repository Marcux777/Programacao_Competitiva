#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float d, vg, vf, raiz;
    while (cin >> d >> vf >> vg)
    {
        raiz = sqrt(d * d + 144);
        if (raiz / vg <= 12.0 / vf)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}