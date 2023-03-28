#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//AHHHHHHHHHHHHHHHHAHAHAHAH CONSEGUI

struct FenwickTree
{
    vector<long long int> tree;
    FenwickTree(int n) : tree(n + 1) {}

    void update(int i, long long int val)
    {
        while (i < tree.size())
        {
            tree[i] += val;
            i += i & -i;
        }
    }

    long long int query(int i)
    {
        long long int sum = 0;
        while (i > 0)
        {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }
};

long long int getInvCount(vector<long long int> &arr)
{
    int n = arr.size();

    // Crie uma cópia do array e ordene-o.

    vector<long long int> sorted_arr(arr);
    sort(sorted_arr.begin(), sorted_arr.end());

    // Mapeia cada elemento para sua posição no array ordenado.

    vector<long long int> rank(n);
    for (int i = 0; i < n; i++)
    {
        rank[i] = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin() + 1;
    }

    // Use uma árvore Fenwick para contar o número de elementos
    // à direita de cada elemento que são menores do que ele.

    FenwickTree ft(n);
    vector<long long int> smaller(n);
    for (int i = n - 1; i >= 0; i--)
    {
        smaller[i] = ft.query(rank[i] - 1);
        ft.update(rank[i], 1);
    }

    // Use uma árvore Fenwick para contar o número de elementos
    // à esquerda de cada elemento que são maiores do que ele.

    ft = FenwickTree(n);
    vector<long long int> greater(n);
    for (int i = 0; i < n; i++)
    {
        greater[i] = ft.query(n) - ft.query(rank[i]);
        ft.update(rank[i], 1);
    }

    // Calcula o número total de inversões usando os arrays de menores e maiores.

    long long int invcount = 0;
    for (int i = 0; i < n; i++)
    {
        invcount += smaller[i] * greater[i];
    }

    return invcount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << getInvCount(v) << "\n";

    return 0;
}
