#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nome1, nome2, jogada1, jogada2;
    int n, n1, n2, n3;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nome1 >> jogada1 >> nome2 >> jogada2;
        cin >> n1 >> n2;
        n3 = n1 + n2;
        if (n3 % 2 == 0)
        {
            if (jogada1 == "PAR")
            {
                cout << nome1 << endl;
            }
            else if (jogada2 == "PAR")
            {
                cout << nome2 << endl;
            }
        }
        else
        {
            if (jogada1 == "IMPAR")
            {
                cout << nome1 << endl;
            }
            else
            {
                cout << nome2 << endl;
            }
        }
    }
}