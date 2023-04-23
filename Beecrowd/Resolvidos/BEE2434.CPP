#include <iostream>
using namespace std;
int main()
{
    int n, s, m;
    int menorv;
    cin >> n >> s;
    menorv = s;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        s += m;
        if (s < menorv)
        {
            menorv = s;
        }
    }
    cout << menorv << endl;
}