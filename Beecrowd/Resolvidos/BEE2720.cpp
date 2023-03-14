#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct para representar um presente
struct Presente
{
    int id;
    int volume;
    // Operador < para ordenação lexicográfica
    bool operator<(const Presente &outro) const
    {
        if (volume != outro.volume)
        {
            return volume > outro.volume; // Ordena por volume decrescente
        }
        return id < outro.id; // Ordena por id crescente
    }
};

bool compare(Presente a, Presente b){
    return a.id < b.id;
}

int main()
{
    //freopen("saida.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<Presente> presentes(n);

        // Lê os presentes e calcula o volume de cada um
        for (int i = 0; i < n; i++)
        {
            int id, h, w, l;
            cin >> id >> h >> w >> l;
            presentes[i].id = id;
            presentes[i].volume = h * w * l;
        }

        // Ordena os presentes
        sort(presentes.begin(), presentes.end());

        vector <Presente> aux;
        for (int i = 0; i < k; i++)
        {
            aux.push_back(presentes[i]);
        }
        sort(aux.begin(), aux.end(), compare);
        for(int i = 0; i < k; i++){
            cout << aux[i].id;
            if (i < k - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}