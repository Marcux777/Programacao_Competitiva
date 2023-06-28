#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> SeparaInter(int l, int r, vector<int> &vet)
{
    vector<int> aux;
    for (int i = l; i < r; i++)
    {
        aux.push_back(vet[i]);
    }
    return aux;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int n, q, l, r, k, g, d;
    cin >> n >> q;
    vector<int> vet(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    while (q--)
    {
        cin >> l >> r >> k >> g >> d;
        char c;
        vector<int> intervalo = SeparaInter(l - 1, r, vet);
        sort(intervalo.begin(), intervalo.end());
        int escolhido = intervalo[k - 1];
        int cont = count(intervalo.begin(), intervalo.end(), escolhido);
        int difg = abs(cont - g);
        int difd = abs(cont - d);
        if (difg == difd)
        {
            c = 'E';
        }
        else
        {
            if (difd < difg)
            {
                c = 'D';
            }
            else
            {
                c = 'G';
            }
        }
        cout << escolhido << " " << cont << " " << c << endl;
    }
}