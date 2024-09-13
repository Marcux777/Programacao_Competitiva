#include <iostream>
using namespace std;
int main()
{
    int n, n1, n2, s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> n1 >> n2;
        s = n1 + n2;
        if (s == 0)
        {
            cout << "PROXYCITY" << endl;
        }
        else if (s == 1)
        {
            cout << "P.Y.N.G." << endl;
        }
        else if (s == 2)
        {
            cout << "DNSUEY!" << endl;
        }
        else if (s == 3)
        {
            cout << "SERVERS" << endl;
        }
        else if (s == 4)
        {
            cout << "HOST!" << endl;
        }
        else if (s == 5)
        {
            cout << "CRIPTONIZE" << endl;
        }
        else if (s == 6)
        {
            cout << "OFFLINE DAY" << endl;
        }
        else if (s == 7)
        {
            cout << "SALT" << endl;
        }
        else if (s == 8)
        {
            cout << "ANSWER!" << endl;
        }
        else if (s == 9)
        {
            cout << "RAR?" << endl;
        }
        else if (s == 10)
        {
            cout << "WIFI ANTENNAS" << endl;
        }
    }
}