#include <bits/stdc++.h>
#include <string>

using namespace std;

class rena
{
public:
    string nome;
    int peso;
    int id;
    double alt;

    rena()
    {
        peso = 0;
        id = 0;
        alt = 0.0;
    }
};

bool comp(rena &a, rena &b)
{
    if (a.peso != b.peso)
    {
        return a.peso > b.peso;
    }
    else
    {
        if (a.id != b.id)
        {
            return a.id < b.id;
        }
        else
        {
            if (a.alt != b.alt)
            {
                return a.alt < b.alt;
            }
            else
            {
                return a.nome < b.nome;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int m, n;
        cin >> n >> m;
        vector<rena> v(n);
        for (int j = 0; j < n; j++)
        {
            rena a;
            cin >> a.nome >> a.peso >> a.id >> a.alt;
            v[j] = a;
        }
        sort(v.begin(), v.end(), comp);

        cout << "CENARIO {" << i << "}\n";

        for (int j = 0; j < m; j++)
        {
            cout << j + 1 << " - " << v[j].nome << endl;
        }
    }
}