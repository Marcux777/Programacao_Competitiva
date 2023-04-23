#include <iostream>
using namespace std;
int main()
{
    double c;
    int n, dia = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        while (c > 1)
        {
            c = c / 2.0;
            dia++;
        }
        cout << dia << " dias" << endl;
        dia = 0;
    }
}