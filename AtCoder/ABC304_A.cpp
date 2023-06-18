#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct pessoa
{
    string nome;
    int id;
};

int main()
{
    int n;
    int menorid = 1000000000;
    pessoa aux;
    queue<pessoa> q;
    cin >> n;
    while (n--)
    {
        pessoa a;
        cin >> a.nome >> a.id;
        if (a.id < menorid)
        {
            aux.id = a.id;
            aux.nome = a.nome;
            menorid = a.id;
        }
        q.push(a);
    }
    queue<pessoa> dir;
    while (q.front().nome != aux.nome)
    {
        dir.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        cout << q.front().nome << endl;
        q.pop();
    }
    while (!dir.empty())
    {
        cout << dir.front().nome << endl;
        dir.pop();
    }
}
