#include <bits/stdc++.h>
using namespace std;

void calc(int *v, int n)
{
    while (n > 0)
    {
        v[n % 10]++;
        n /= 10;
    }
}
int main()
{
    long long int num;
    int n;
    cin >> n;
    while (n)
    {
        cin >> num;
        int vet[10] = {0};
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < num; j++)
            {
                calc(vet, j + 1);
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (i < 9)
            {
                cout << vet[i] / 10 << " ";
            }
            else
            {
                cout << vet[i] / 10 << endl;
            }
        }
        n--;
    }
}