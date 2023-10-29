#include <bits/stdc++.h>

using namespace std;

// Definindo o módulo
#define mod 998244353

// Função para calcular a potência de um número em módulo mod
long long power(long long a, long long b)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b & 1ll)
        {
            x = (x * y) % mod; // Se b é ímpar, multiplica x por y
        }
        y = (y * y) % mod; // Quadrado de y
        b >>= 1;           // Divide b por 2
    }
    return x % mod;
}

// Função para calcular o inverso modular de um número
long long modular_inverse(long long n)
{
    return power(n, mod - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;                            // Lê a entrada do usuário
    long long invn = modular_inverse(n); // Calcula o inverso modular de n
    long long p = invn, res = 0;

    // Loop para ler os números de entrada e calcular o resultado
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a; // Lê o próximo número de entrada
        res += p * a;
        res %= mod; // Atualiza o resultado
        p += p * invn;
        p %= mod; // Atualiza p
    }

    cout << res << "\n"; // Imprime o resultado

    return 0;
}
