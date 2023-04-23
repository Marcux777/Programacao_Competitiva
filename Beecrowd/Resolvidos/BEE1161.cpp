#include <iostream>
using namespace std;
int main()
{
    long long int n, m;
    long long int fat1, fat2;

    while (cin >> n >> m)
    {
        fat1 = 1;
        fat2 = 1;
        for (int i = n; i > 0; i--)
        {
            fat1 *= i;
        }
        for (int i = m; i > 0; i--)
        {
            fat2 *= i;
        }
        cout << fat1 + fat2 << endl;
    }
}