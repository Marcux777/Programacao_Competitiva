#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double f1, f2, s;
    cin >> f1 >> f2;
    cout << fixed << setprecision(6);
    cout << ((((1.0 + f1 / 100.00) * (1.0 + f2 / 100.00)) - 1.0) * 100.0) << endl;
}