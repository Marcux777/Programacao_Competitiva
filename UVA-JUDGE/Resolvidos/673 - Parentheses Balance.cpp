#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d\n", &t);
    string linha;
    for (int i = 0; i < t; i++)
    {
        stack<char> abre;
        getline(cin, linha);
        for (int j = 0; linha[j] != '\0'; j++)
        {
            if (linha[j] == '(' || linha[j] == '[')
            {
                abre.push(linha[j]);
            }
            else
            {
                if (abre.empty())
                {
                    abre.push('a');
                    break;
                }
                else
                {
                    if (linha[j] == ')' && abre.top() == '(')
                    {
                        abre.pop();
                    }
                    else
                    {
                        if (linha[j] == ']' && abre.top() == '[')
                        {
                            abre.pop();
                        }
                        else
                        {
                            abre.push('a');
                            break;
                        }
                    }
                }
            }
        }
        if (abre.empty())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}