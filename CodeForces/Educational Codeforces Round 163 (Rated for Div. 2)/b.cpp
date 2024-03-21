#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

/*Você é dado um array de inteiros a de comprimento n.

Você pode executar a seguinte operação qualquer número de vezes (possivelmente zero):
pegar qualquer elemento do array a, que é pelo menos 10, excluí-lo e, em vez disso, inserir os
dígitos que o elemento consistia na mesma posição, na ordem em que aparecem nesse elemento.

Por exemplo:

- se aplicarmos esta operação ao 3º elemento do array [12,3,45,67], então o array se torna [12,3,4,5,67].
- se aplicarmos esta operação ao 2º elemento do array [2,10], então o array se torna [2,1,0].
Sua tarefa é determinar se é possível fazer a ordenada em ordem não decrescente usando a operação
mencionada acima qualquer número de vezes (possivelmente zero). Em outras palavras, você tem que
determinar se é possível transformar o array a de tal forma que a1≤a2≤⋯≤ak, onde k é o comprimento atual do array a.

Entrada
A primeira linha contém um único inteiro t (1≤t≤103) — o número de casos de teste.

Cada caso de teste consiste em duas linhas:

a primeira linha contém um único inteiro n (2≤n≤50).
a segunda linha contém n inteiros a1,a2,…,an (0≤ai≤99).
Saída
Para cada caso de teste, imprima SIM se for possível fazer a ordenada em ordem não
decrescente usando a operação mencionada acima; caso contrário, imprima NÃO.

Você pode imprimir cada letra em qualquer caso. Por exemplo, sim, Sim, YeS serão todos reconhecidos
como uma resposta positiva.*/

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        queue<int> l;
        int n, x;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x >= 10)
            {
                for (auto it : to_string(x))
                {
                    if (it != '0')
                        l.push(it - '0');
                }
            }else{
                l.push(x);
            }
        }
        int ant = l.front();
        l.pop();
        while (l.size() && l.front() >= ant)
        {
            ant = l.front();
            l.pop();
        }
        cout << (l.empty() ? "YES" : "NO") << endl;
    }
}