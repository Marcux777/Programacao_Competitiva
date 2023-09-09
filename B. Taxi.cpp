#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int soma = 0, cont = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        soma += x;
        if(soma > 4){
            cont++;
            soma -= x;
        }else{
            cont++;
            soma = x;
        }
    }

    cout << cont << endl;

}