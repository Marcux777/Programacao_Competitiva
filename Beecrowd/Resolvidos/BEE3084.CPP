#include <iostream>
using namespace std;
int main()
{
    int h, m;
    while (cin >> h >> m)
    {

        h = h / 30;
        m = m / 6;

        printf("%02d:%02d\n", h, m);
    }
}