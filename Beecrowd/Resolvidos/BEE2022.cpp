#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

class produto
{
public:
    string name;
    int priority;
    double price;
    produto()
    {
        priority = 0;
        price = 0.0;
    }
};

bool comp(produto a, produto b)
{
    if (a.priority != b.priority)
    {
        return a.priority > b.priority;
    }
    if (a.price != b.price)
    {
        return a.price < b.price;
    }
    return a.name < b.name;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    cout << fixed << setprecision(2);
    string nome;
    while (cin >> nome)
    {

        int q;
        cin >> q;
        vector<produto> v;
        for (int i = 0; i < q; i++)
        {
            produto a;
            cin.ignore();
            getline(cin, a.name);
            cin >> a.price;
            cin >> a.priority;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), comp);
        cout << "Lista de " << nome << endl;
        for (auto it : v)
        {
            cout << it.name << " - R$" << it.price << endl;
        }
        cout << endl;
    }
}