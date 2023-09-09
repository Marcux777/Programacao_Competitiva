#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int idPar, idImpar;
    int contPar = 0, contImpar = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x & 1){
            contImpar++;
            idImpar = i+1;
        }else{
            contPar++;
            idPar = i+1;
        }
    }
    if(contImpar == 1){
        cout << idImpar << endl;
    }else{
        cout << idPar << endl;
    }
}