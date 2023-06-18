#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(8);
    bool ok = true;
    for (int i = 0; i < 8; i++)
    {
        cin >> v[i];
        if (v[i] == 9)
        {
            ok = false;
        }
    }
    if (ok)
    {
        cout << "S\n";
    }
    else
    {
        cout << "F\n";
    }
}