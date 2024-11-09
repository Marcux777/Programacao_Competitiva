#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a = 1, b = 2;
    long long soma = 2; // Inicia com o segundo termo que é par

    while(true){
        long long proximo = a + b;
        if(proximo > 4000000) break;
        if(proximo % 2 == 0){
            soma += proximo;
        }
        a = b;
        b = proximo;
    }
    cout << "A soma dos termos pares da sequência de Fibonacci abaixo de quatro milhões é: " << soma << endl;
    return 0;
}