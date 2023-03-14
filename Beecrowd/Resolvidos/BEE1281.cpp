#include <bits/stdc++.h>

using namespace std;

int main(){

    map<string, double> mp;
    int n, m,p, quant; 
    double compras;
    string a;
    double b;

    cin >> n;
    while(n--){
        compras = 0;
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            mp[a] = b;
        }
        cin >> p;
        for(int i = 0; i < p; i++){
            cin >> a >> quant;
            compras += quant * mp.find(a)->second;
        }
        printf("R$ %.2lf\n", compras);
    }
}