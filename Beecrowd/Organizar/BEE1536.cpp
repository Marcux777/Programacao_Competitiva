#include <iostream>
using namespace std;
int main()
{
    int n, M[100], V[100], soma1, soma2;
    char dp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> M[i] >> dp >> V[i];
        cin >> V[i + 1] >> dp >> M[i + 1];
        soma1 = M[i] + M[i + 1];
        soma2 = V[i] + V[i + 1];
        if (soma1 > soma2)
        {
            cout << "Time 1" << endl;
        }
        else if (soma2 > soma1)
        {
            cout << "Time 2" << endl;
        }
        else if (soma2 == soma1)
        {
            if (V[i] > M[i + 1])
            {
                cout << "Time 2" << endl;
            }
            else if (V[i] < M[i + 1])
            {
                cout << "Time 1" << endl;
            }
            else
            {
                cout << "Penaltis" << endl;
            }
        }
    }
}