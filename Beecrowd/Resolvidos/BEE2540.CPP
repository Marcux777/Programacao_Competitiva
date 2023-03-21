#include <iostream>
#include <cmath>
using namespace std;
int main(){
        int n, contra,favor, voto;
        double quant;
    while(cin >> n){
        contra = 0;
        favor = 0;
        for(int i = 0; i < n; i++){
            cin >> voto;
            if(voto == 0){
                contra++;
            } else {
                favor++;
            }
        }
        quant = n*2.0/3.0;
        if(favor >= quant){
            cout << "impeachment" << endl;
        } else {
            cout << "acusacao arquivada" << endl;
        }
    }
}