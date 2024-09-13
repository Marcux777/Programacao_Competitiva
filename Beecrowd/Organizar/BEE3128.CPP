#include <iostream>

using namespace std;

int main()
{
    int id1, id2;

    cin >> id1;
    cin >> id2;
    if (id1 < 6 || id2 < 6)
    {
        cout << "NO" << endl;
    }
    else if (id1 >= 18 || id2 >= 18)
    {
        cout << "YES" << endl;
    }
    else if (id1 >= 14 && id2 >= 14)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}