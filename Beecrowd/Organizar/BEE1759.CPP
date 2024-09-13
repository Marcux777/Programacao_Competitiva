#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string h;
    h = "Ho ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i < n)
        {
            cout << h;
        }
        if (i == n)
        {
            cout << "Ho!" << endl;
        }
    }
}