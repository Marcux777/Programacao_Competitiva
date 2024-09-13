#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s); // lê a string S

    stack<char> stk; // inicializa a pilha vazia

    for (char c : s)
    {
        if (c == '(')
        { // se encontrou um parêntese de abertura, adiciona na pilha
            stk.push(c);
        }
        else if (c == ')')
        { // se encontrou um parêntese de fechamento, remove da pilha (se houver)
            if (!stk.empty())
            {
                stk.pop();
            }
        }
    }

    if (!stk.empty())
    { // se a pilha não está vazia, ainda há assuntos pendentes
        cout << "Ainda temos " << stk.size() << " assunto(s) pendente(s)!\n";
    }
    else
    { // caso contrário, não há mais assuntos pendentes
        cout << "Partiu RU!\n";
    }

    return 0;
}
