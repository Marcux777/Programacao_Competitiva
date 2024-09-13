#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct doende
{
    string nome;
    int id;
};

bool comp(doende a, doende b)
{
    if (a.id != b.id)
    {
        return a.id > b.id;
    }
    else
    {
        return a.nome < b.nome;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<doende> vec(n);
    for (int i = 0; i < n; i++)
    {
        doende a;
        cin >> a.nome >> a.id;
        vec[i] = a;
    }
    sort(vec.begin(), vec.end(), comp);
    int tam = n / 3;
    vector<doende> times[tam];
    for (int i = 0; i < n; i++)
    {
        times[i % tam].push_back(vec[i]);
    }
    for (int i = 0; i < tam; i++)
    {
        cout << "Time " << i + 1 << endl;
        for (int j = 0; j < times[i].size(); j++)
        {
            cout << times[i][j].nome << " " << times[i][j].id << endl;
        }
        cout << endl;
    }
}