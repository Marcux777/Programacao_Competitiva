#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    unordered_map<int, int> freq;
};

// Função para construir a árvore de segmentos
void build_tree(vector<Node> &tree, vector<int> &v, int node, int start, int end)
{
    if (start == end)
    {
        // Se o nó representa um único elemento do vetor
        // Armazena a frequência desse elemento no nó
        tree[node].freq[v[start]]++;
    }
    else
    {
        // Se o nó representa um intervalo com mais de um elemento
        // Divide o intervalo ao meio e constrói a árvore para os dois subintervalos
        int mid = (start + end) / 2;
        build_tree(tree, v, 2 * node + 1, start, mid);
        build_tree(tree, v, 2 * node + 2, mid + 1, end);
        // Combina as informações dos dois subintervalos
        for (auto it : tree[2 * node + 1].freq)
        {
            tree[node].freq[it.first] += it.second;
        }
        for (auto it : tree[2 * node + 2].freq)
        {
            tree[node].freq[it.first] += it.second;
        }
    }
}

// Função para consultar a árvore de segmentos
unordered_map<int, int> query_tree(vector<Node> &tree, vector<int> &v, int node, int start, int end, int l, int r)
{
    if (l <= start && r >= end)
    {
        // Se o intervalo do nó está completamente dentro do intervalo da consulta
        // Retorna a informação armazenada no nó
        return tree[node].freq;
    }
    else if (r < start || l > end)
    {
        // Se o intervalo do nó está completamente fora do intervalo da consulta
        // Retorna uma mapa vazio
        return {};
    }
    else
    {
        // Se o intervalo do nó intersecta o intervalo da consulta
        // Consulta os dois subintervalos e combina as informações retornadas
        unordered_map<int, int> freq;
        int mid = (start + end) / 2;
        unordered_map<int, int> left_freq = query_tree(tree, v, 2 * node + 1, start, mid, l, r);
        unordered_map<int, int> right_freq = query_tree(tree, v, 2 * node + 2, mid + 1, end, l, r);
        for (auto it : left_freq)
        {
            freq[it.first] += it.second;
        }
        for (auto it : right_freq)
        {
            freq[it.first] += it.second;
        }
        return freq;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<Node> tree(4 * n);
    build_tree(tree,v ,0 ,0 ,n -1);

    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        
         // Consulta a árvore de segmentos para obter a frequência de cada elemento no intervalo [l,r]
         unordered_map<int,int> freq = query_tree(tree,v ,0 ,0 ,n -1 ,l ,r);
        
         // Conta o número de elementos que ocorrem exatamente x vezes no intervalo [l,r]
         int cont = 0;
        
         for(auto it: freq){
             if(it.first == it.second){
                 cont++;
             }
         }
        
         cout << cont << endl;
        
     }

}