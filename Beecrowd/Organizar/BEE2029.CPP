#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double v, d, h, area, r;
    cout << setprecision(2) << fixed;
    while (cin >> v)
    {                             // volume
        cin >> d;                 // diametro;
        r = d / 2;                // raio
        h = v / ((r * r) * 3.14); // altura
        area = 3.14 * r * r;      // area da boca do recipiente
        cout << "ALTURA = " << h << endl;
        cout << "AREA = " << area << endl;
    }
}