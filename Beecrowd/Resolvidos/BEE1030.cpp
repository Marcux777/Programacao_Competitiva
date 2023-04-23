#include <iostream>
using namespace std;
int main()
{
    int nc, n, k, aux;
    cin >> nc;
    if (nc == 1)
    {
        return 0;
    }
    for (int i = 0; i < nc; i++)
    {
        cin >> n >> k;
        aux = 0;
        for (int j = 2; j <= n; j++)
        {
            aux = (aux + k) % j;
        }
        cout << "Case " << i + 1 << ": ";
        cout << aux + 1 << endl;
    }
}