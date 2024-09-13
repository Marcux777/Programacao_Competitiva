#include <iostream>
using namespace std;
int main()
{
    int t[4], soma;
    soma = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> t[i];
        soma += t[i];
    }
    cout << soma - 3 << endl;
}