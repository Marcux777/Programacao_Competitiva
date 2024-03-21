/*Um colecionador de livros raros recentemente descobriu um livro escrito em uma língua
desconhecida que usava os mesmos caracteres que o inglês.
O livro continha um índice curto, mas a ordem dos itens no índice era diferente do que se
esperaria se os caracteres fossem ordenados da mesma forma que no alfabeto inglês.
O colecionador tentou usar o índice para determinar a ordenação dos caracteres
(ou seja, a sequência de colação) do alfabeto estranho, mas desistiu com frustração diante do tédio da tarefa.
Você deve escrever um programa para concluir o trabalho do colecionador.
Em particular, seu programa irá receber um conjunto de strings que foi ordenado de acordo
com uma sequência de colação específica e determinar qual é essa sequência.
Entrada
A entrada consiste em uma lista ordenada de strings de letras maiúsculas,
uma string por linha. Cada string contém no máximo 20 caracteres.
O fim da lista é sinalizado por uma linha com o caractere único ‘#’.
Nem todas as letras são necessariamente usadas, mas a lista implicará uma ordenação completa entre aquelas letras que são usadas.
Saída
Sua saída deve ser uma única linha contendo letras maiúsculas na ordem que especifica a sequência de colação usada para
produzir o arquivo de dados de entrada.*/

#include <bits/stdc++.h>

using namespace std;

int n;             
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;


int main()
{
    
}