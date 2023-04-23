#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> pilha;
    char diam[1001];
    int n, cont;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        while (pilha.size())
        {
            pilha.pop();
        }
        cont = 0;
        scanf("%s", &diam);
        for (int j = 0; diam[j]; j++)
        {
            if (diam[j] == '<')
            {
                pilha.push(diam[j]);
            }
            else
            {
                if (diam[j] == '>')
                {
                    if (pilha.size() > 0)
                    {
                        pilha.pop();
                        cont++;
                    }
                }
            }
        }
        cout << cont << endl;
    }
}