#include <iostream>
#include <vector>
using namespace std;

vector<char> posfixoPorInfixoPrefixo(vector<char> &infixo, vector<char> &prefixo)
{
    if (infixo.empty() || prefixo.empty())
    {
        return vector<char>();
    }

    char raiz = prefixo[0];
    int index_raiz_infixo = -1;
    for (int i = 0; i < infixo.size(); i++)
    {
        if (infixo[i] == raiz)
        {
            index_raiz_infixo = i;
            break;
        }
    }

    // Obter a subárvore esquerda e direita do percurso infixo
    vector<char> sub_arvore_esquerda_infixo(infixo.begin(), infixo.begin() + index_raiz_infixo);
    vector<char> sub_arvore_direita_infixo(infixo.begin() + index_raiz_infixo + 1, infixo.end());

    // Obter os percursos pré-fixado das subárvores esquerda e direita
    vector<char> sub_arvore_esquerda_prefixo(prefixo.begin() + 1, prefixo.begin() + 1 + sub_arvore_esquerda_infixo.size());
    vector<char> sub_arvore_direita_prefixo(prefixo.begin() + 1 + sub_arvore_esquerda_infixo.size(), prefixo.end());

    // Obter os percursos pós-fixados das subárvores
    vector<char> sub_arvore_esquerda_posfixo = posfixoPorInfixoPrefixo(sub_arvore_esquerda_infixo, sub_arvore_esquerda_prefixo);
    vector<char> sub_arvore_direita_posfixo = posfixoPorInfixoPrefixo(sub_arvore_direita_infixo, sub_arvore_direita_prefixo);

    // Concatenar os percursos pós-fixados das subárvores com a raiz
    vector<char> posfixo;
    posfixo.insert(posfixo.end(), sub_arvore_esquerda_posfixo.begin(), sub_arvore_esquerda_posfixo.end());
    posfixo.insert(posfixo.end(), sub_arvore_direita_posfixo.begin(), sub_arvore_direita_posfixo.end());
    posfixo.push_back(raiz);

    return posfixo;
}

int main()
{
    // freopen("saida.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        vector<char> prefixo, infixo;
        string s;
        cin >> s;
        for (auto i : s)
        {
            prefixo.push_back(i);
        }
        cin >> s;
        for (auto i : s)
        {
            infixo.push_back(i);
        }
        vector<char> posfixo = posfixoPorInfixoPrefixo(infixo, prefixo);
        for (auto i : posfixo)
        {
            cout << i;
        }
        cout << endl;
    }
}