#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            cout << "vai ter copa!" << endl;
        }
        if (n >= 1)
        {
            cout << "vai ter duas!" << endl;
        }
    }
}