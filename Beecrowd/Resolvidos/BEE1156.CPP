#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float quo = 3, div = 2, s = 1;
    cout << setprecision(2) << fixed;
    while (quo < 39)
    {
        s += quo / div;
        quo += 2;
        div *= 2;
    }
    cout << s << endl;
}