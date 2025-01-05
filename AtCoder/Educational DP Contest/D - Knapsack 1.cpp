#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN

vector<vector<int>> DP;
vector<vector<int>> mat;
vector<int> peso, valor;

int n, w;

int f(int item, int weight)
{
    if (item == n)
        return 0;
    if (weight == w)
        return 0;

    if (DP[item][weight] != -1)
        return DP[item][weight];

    int r = f(item + 1, weight); // Não peguei

    if (weight + peso[item] <= w){
        int r2 = f(item + 1, weight + peso[item]) + valor[item]; //peguei
        r = max(r, r2);
    }
    return DP[item][weight] = r;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w;
    peso = valor = vector<int>(n);
    DP = vector<vector<int>>(n, vector<int>(w, -1));
    for (int i = 0; i < n; i++)
        cin >> peso[i] >> valor[i];

    cout << f(0, 0) << endl;

    /*for(int i = 0; i < n; i++){
        if(i +1 < n && DP[i][0]+mat[i][0] <= w){ // se eu posso pegar
            //maior valor
            DP[i+1][1] = max(DP[i+1][1], DP[i][1] + abs(mat[i+1][1] - mat[i][1]));

        }
    }*/
}