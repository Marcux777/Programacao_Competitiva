#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    double g, pi, h, a, v;
    double vx, vy, tmax, temp, total;
    g = 9.80665;
    pi = 3.14159;
    int p1, p2, n;
    cout << setprecision(5) << fixed;
    while (cin >> h)
    {
        cin >> p1 >> p2;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> v;
            vx = v * cos(a / 180.0 * pi);
            vy = v * sin(a / 180.0 * pi);
            tmax = vy / g;
            temp = sqrt((h * 2.0 / g) + (tmax * tmax)) + tmax;
            total = temp * vx;
            if (total >= p1 && total <= p2)
            {
                cout << total << " -> DUCK" << endl;
            }
            else
            {
                cout << total << " -> NUCK" << endl;
            }
        }
    }
}