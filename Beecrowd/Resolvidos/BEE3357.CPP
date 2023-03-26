#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<string> roda;
    string nome;
    int n;
    double l, q;
    cin >> n >> l >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> nome;
        roda.push(nome);
    }
    while (l > q)
    {
        l = l - q;
        roda.push(roda.front());
        roda.pop();
    }
    cout << roda.front() << " " << l << endl;
}
