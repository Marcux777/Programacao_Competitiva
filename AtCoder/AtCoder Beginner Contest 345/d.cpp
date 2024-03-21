#include <bits/stdc++.h>
using namespace std;

/***Enunciado do Problema**

Dado um tabuleiro com **H** linhas e **W** colunas, 
onde cada célula tem um lado de comprimento **1**, e temos **N** peças de 
quebra-cabeça. A **i-ésima** peça (**1≤i≤N**) é um retângulo de 
tamanho **A_i × B_i**.

Determine se é possível colocar as peças no tabuleiro de 
forma que todas as seguintes condições sejam satisfeitas:

1. Cada célula é coberta exatamente por uma peça.
2. É permitido ter peças não utilizadas.
3. As peças podem ser giradas ou espelhadas ao serem colocadas. 
No entanto, cada peça deve estar alinhada com as bordas das células 
sem se estender para fora do tabuleiro.*/

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

int n, w, h;
vector<vector<vector<int>>> dp;
vector<int> a, b;

bool f(int x, int y, int z) {
    if (x == n) return y == 0 && z == 0;

    if (dp[x][y][z] != -1) return dp[x][y][z];

    bool result = f(x + 1, y, z); // Não usar a peça i

    if (y >= a[x] && z >= b[x]) {
        result |= f(x + 1, y - a[x], z - b[x]); // Usar a peça i
    }

    return dp[x][y][z] = result;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> w >> h;
    a.resize(n); b.resize(n);
    dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(w + 1, vector<int>(h + 1, -1)));
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    cout << (f(0, w, h) ? "Yes" : "No") << endl;
    
}