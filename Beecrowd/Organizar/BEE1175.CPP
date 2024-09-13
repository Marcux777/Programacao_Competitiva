#include <iostream>
using namespace std;
void organiza_vetor(int *x, int j = 19, int i = 0)
{
    cout << "N[" << i << "] = " << x[j] << endl;
    if (j > 0)
    {
        organiza_vetor(x, --j, ++i);
    }
}
int main()
{
    int v[20];
    for (int i = 0; i < 20; i++)
    {
        cin >> v[i];
    }
    organiza_vetor(v);
}