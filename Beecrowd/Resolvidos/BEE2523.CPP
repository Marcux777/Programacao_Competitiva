#include <iostream>
#include <string>
using namespace std;
int main()
{
    char alfa[30];
    int n = 0, pos;
    while (scanf("%s", alfa) != EOF)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> pos;
            cout << alfa[pos - 1];
        }
        cout << endl;
    }
}