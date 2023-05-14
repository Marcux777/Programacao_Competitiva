#include <iostream>
#include <string>
#include <vector>

using namespace std;

int buscaBinaria(vector<long long int> &v)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        long long TimeA = 0;
        long long TimeB = 0;

        for (int i = 0; i <= mid; i++)
        {
            TimeA += v[i] * (mid - i + 1);
        }
        for (int i = mid + 1; i < v.size(); i++)
        {
            TimeB += v[i] * (i - mid);
        }

        if (TimeA == TimeB)
        {
            return mid;
        }
        else
        {
            if (TimeA > TimeB)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w",stdout);
    int n;
    while (cin >> n && n)
    {
        vector<string> Est(n);
        vector<long long int> v(n);
        for (int i = 0; i < n; i++)
        {
            string nome;
            cin >> nome;
            Est[i] = nome;
            for (int j = 0; j < nome.size(); j++)
            {
                v[i] += nome[j];
            }
        }
        int resp = buscaBinaria(v);
        if (resp == -1)
        {
            cout << "Impossibilidade de empate.\n";
        }
        else
        {
            cout << Est[resp] << endl;
        }
    }
}
