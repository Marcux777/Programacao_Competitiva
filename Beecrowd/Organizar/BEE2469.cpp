#include <iostream>
using namespace std;
int main()
{
    int n, maior = 0, maiorn;
    int nota[10000], rp[10000] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nota[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nota[i] == nota[j])
            {
                rp[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (rp[i] > maior)
        {
            maior = rp[i];
            maiorn = nota[i];
        }
        if (rp[i] == maior)
        {
            if (nota[i] > maiorn)
            {
                maiorn = nota[i];
            }
        }
    }
    cout << maiorn << endl;
}