#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    int n;
    cin >> n;

    stack<int> pilha;
    int menor = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;

        if (op == "PUSH")
        {
            int v;
            cin >> v;

            pilha.push(v);
            menor = min(menor, v);
        }
        else
        {
            if (op == "POP")
            {
                if (!pilha.empty())
                {
                    int v = pilha.top();
                    pilha.pop();
                    if (v == menor)
                    {
                        menor = INT_MAX;
                        stack<int> temp;
                        while (!pilha.empty())
                        {
                            int x = pilha.top();
                            pilha.pop();
                            menor = min(menor, x);
                            temp.push(x);
                        }
                        while (!temp.empty())
                        {
                            int x = temp.top();
                            temp.pop();
                            pilha.push(x);
                        }
                    }
                }
                else
                {
                    cout << "EMPTY" << endl;
                }
            }
            else
            {
                if (op == "MIN")
                {
                    if (!pilha.empty())
                    {
                        cout << menor << endl;
                    }
                    else
                    {
                        cout << "EMPTY" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
