#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 0)
        {
            cout << "NULL" << endl;
        }
        else
        {
            if (x % 2 == 0)
            {
                cout << "EVEN ";
            }
            else
            {
                cout << "ODD ";
            }
            if (x > 0)
            {
                cout << "POSITIVE" << endl;
            }
            else
            {
                cout << "NEGATIVE" << endl;
            }
        }
    }
}