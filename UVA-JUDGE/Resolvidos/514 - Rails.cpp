#include <iostream>
#include <stack>
using namespace std;
int main()
{

    int n, aux, vag[1000];
    int aux2 = 1, aux3 = 1, lido;
    while (aux2)
    {
        stack<int> a;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        while (aux3)
        {
            stack<int> a;
            aux = 1;
            for (int i = 1; i <= n; i++)
            {
                cin >> lido; // lido de valor lido
                if (lido == 0)
                {
                    break;
                }
                vag[i] = lido; // vetor recebe o valor lido;
                a.push(i);
                while (!a.empty() && vag[aux] == a.top())
                {
                    aux++;
                    a.pop();
                }
            }
            if (lido == 0)
            {
                cout << endl;
                break;
            }
            else
            {
                if (a.size() == 0)
                {
                    cout << "Yes\n";
                }
                else
                {
                    cout << "No\n";
                }
            }
        }
    }
}