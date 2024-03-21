#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

/*Você recebe um número inteiro n. Sua tarefa é construir uma string de letras latinas maiúsculas. 
Deve haver exatamente n caracteres especiais nesta string. 
Vamos chamar um caractere de especial se ele for igual exatamente a um de seus vizinhos.

Por exemplo, existem 6 caracteres especiais na string AAABAACC (nas posições: 1, 3, 5, 6, 7 e 8).

Imprima qualquer string adequada ou informe que não existe tal string.

Entrada
A primeira linha contém um único inteiro t (1≤t≤50) — o número de casos de teste.

A única linha de cada caso de teste contém um único inteiro n (1≤n≤50).

Saída
Para cada caso de teste, imprima a resposta da seguinte forma:

se não houver uma string adequada, imprima uma linha contendo a string NÃO;
caso contrário, imprima duas linhas. A primeira linha deve conter a string SIM; na segunda linha imprima uma 
string de comprimento máximo 200 — a resposta em si (pode-se mostrar que se algumas respostas existem, 
então existe uma resposta de comprimento máximo 200). Se houver várias soluções, imprima qualquer uma delas.*/

string f(int n){
    string aux;
    for(int i = 0; i < n/2; i++){
        aux += 'A' + i;
        aux += 'A' + i;
    }
    return aux;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2 != 0) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << f(n) << endl;
        }
    }
}