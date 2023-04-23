#include <iostream>
using namespace std;
int main()
{
    int nota;
    cin >> nota;
    if (nota == 0)
    {
        cout << "E" << endl;
    }
    else if (nota > 0 && nota <= 35)
    {
        cout << "D" << endl;
    }
    else if (nota > 35 && nota <= 60)
    {
        cout << "C" << endl;
    }
    else if (nota > 60 && nota <= 85)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "A" << endl;
    }
}