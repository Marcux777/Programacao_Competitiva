#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d, m, y;
        char c;
        cin >> d >> c >> m >> c >> y;
        bool a = (d + 1 == m && m + 1 == y % 100);
        cin >> d >> c >> m >> c >> y;
        bool b = (d + 1 == m && m + 1 == y % 100);
        cout << (a != b) << endl;
    }
}